robot = rigidBodyTree("DataFormat","column","MaxNumBodies",3);
L1 = 0.3;
L2 = 0.3;

body = rigidBody('link1');
joint = rigidBodyJoint('joint1', 'revolute');
setFixedTransform(joint,trvec2tform([0 0 0]));
joint.JointAxis = [0 0 1];
body.Joint = joint;
addBody(robot,body,'base');

body = rigidBody('link2');
joint = rigidBodyJoint('joint2', 'revolute');
setFixedTransform(joint,trvec2tform([L1 0 0]));
joint.JointAxis = [0 0 1];
body.Joint = joint;
addBody(robot,body,'link1');

body = rigidBody('tool');
joint = rigidBodyJoint('fix1','fixed');
setFixedTransform(joint, trvec2tform([L2, 0, 0]));
body.Joint= joint;
addBody(robot,body,'link2');

%the trajectory is the following code block
t = (0:0.2:10)';
count = length(t);
center = [0.3 0.1 0];
radius = 0.15;
theta = t*(2*pi/t(end));
points = center + radius*[cos(theta) sin(theta) zeros(size(theta))];

q0 = homeConfiguration(robot);
ndof = length(q0);
qs = zeros(count,ndof);

ik = inverseKinematics("RigidBodyTree",robot);
weights = [0, 0, 0, 1, 1, 0];
endEffector = 'tool';

qInitial = q0;
for i = 1:count
    point = points(i,:);
    qSol = ik(endEffector,trvec2tform(point), weights, qInitial);
    qs(i,:) = qSol;
    qInitial = qSol;
end

figure
show(robot,qs(1,:)');
view(2);
ax = gca;
ax.Projection = 'orthographic';
hold on
plot(points(:,1), points(:,2),'k')
axis([-0.1,0.7,-0.3,0.5])

framesPerSecond = 15;
r = rateControl(framesPerSecond);
for i = 1:count
    show(robot,qs(i,:)', 'PreservePlot',false);
    drawnow
    waitfor(r);
end
