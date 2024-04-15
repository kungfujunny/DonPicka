% Simscape(TM) Multibody(TM) version: 23.2

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(5).translation = [0.0 0.0 0.0];
smiData.RigidTransform(5).angle = 0.0;
smiData.RigidTransform(5).axis = [0.0 0.0 0.0];
smiData.RigidTransform(5).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [0 3.9370078740157481 0.19685039370078758];  % in
smiData.RigidTransform(1).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(1).axis = [1 0 0];
smiData.RigidTransform(1).ID = "B[Part_0_Link_0-1:-:Part_1_Arm_1-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [-3.3464566929133879 2.2204460492503131e-15 -0.68897637795275868];  % in
smiData.RigidTransform(2).angle = 1.7409706340421393e-15;  % rad
smiData.RigidTransform(2).axis = [-0.92873531632368345 -0.37074345875975695 2.9972771838924849e-16];
smiData.RigidTransform(2).ID = "F[Part_0_Link_0-1:-:Part_1_Arm_1-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [3.3464566929133843 0 -0.09842519685039379];  % in
smiData.RigidTransform(3).angle = 0;  % rad
smiData.RigidTransform(3).axis = [0 0 0];
smiData.RigidTransform(3).ID = "B[Part_1_Arm_1-1:-:Part_2_Arm_2-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [-3.3464566929133879 4.4408920985006262e-16 -0.6889763779527549];  % in
smiData.RigidTransform(4).angle = 1.7409706340421395e-15;  % rad
smiData.RigidTransform(4).axis = [0.94379912773092667 0.33051960077178744 2.7154276827520214e-16];
smiData.RigidTransform(4).ID = "F[Part_1_Arm_1-1:-:Part_2_Arm_2-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [-10.567679076698784 0 -5.7572414906135387];  % in
smiData.RigidTransform(5).angle = 0;  % rad
smiData.RigidTransform(5).axis = [0 0 0];
smiData.RigidTransform(5).ID = "RootGround[Part_0_Link_0-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(3).mass = 0.0;
smiData.Solid(3).CoM = [0.0 0.0 0.0];
smiData.Solid(3).MoI = [0.0 0.0 0.0];
smiData.Solid(3).PoI = [0.0 0.0 0.0];
smiData.Solid(3).color = [0.0 0.0 0.0];
smiData.Solid(3).opacity = 0.0;
smiData.Solid(3).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.39419228881306612;  % kg
smiData.Solid(1).CoM = [-0.031390377571845832 0.60287328492838832 0.00097849405506042269];  % in
smiData.Solid(1).MoI = [0.96507023140753612 1.5380793925453631 0.98217224618542509];  % kg*in^2
smiData.Solid(1).PoI = [-0.0012860200701298248 -1.2058486498676538e-05 0.019399025727786998];  % kg*in^2
smiData.Solid(1).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "Part_0_Link_0*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.11356036148800694;  % kg
smiData.Solid(2).CoM = [-10.500206035040929 -3.4610857505174244 0.29021237081394546];  % mm
smiData.Solid(2).MoI = [16.020328389934495 361.23379776702518 371.91987988334932];  % kg*mm^2
smiData.Solid(2).PoI = [-0.1149293241146689 2.7884527341358774 3.3937816491011565];  % kg*mm^2
smiData.Solid(2).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "Part_1_Arm_1*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.15102655318191424;  % kg
smiData.Solid(3).CoM = [25.416361750335039 -2.035710352547679 0.24080150346640417];  % mm
smiData.Solid(3).MoI = [45.163667306859296 806.06877193433581 812.43866283513228];  % kg*mm^2
smiData.Solid(3).PoI = [-0.074033544316621319 4.0155579911672792 -9.9627070054682729];  % kg*mm^2
smiData.Solid(3).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = "Part_2_Arm_2*:*Default";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = -118.44076693633356;  % deg
smiData.RevoluteJoint(1).ID = "[Part_0_Link_0-1:-:Part_1_Arm_1-1]";

smiData.RevoluteJoint(2).Rz.Pos = 2.4611594439903213;  % deg
smiData.RevoluteJoint(2).ID = "[Part_1_Arm_1-1:-:Part_2_Arm_2-1]";

