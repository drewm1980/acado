clc;
clear all;
close all;

h = 0.1;
N = 200;                            
    
acadoSet('problemname', 'pendulum');

DifferentialState x y alpha dx dy dalpha;
AlgebraicState ddalpha Fx Fy;
Control u;

m = 1;
I = 1;
g = 9.81;
L = 1;
c = 0.7;

%% Differential Equation
f = [ dx; ...
    dy; ...
    dalpha; ...
    1/m*(Fx+u); ...
    1/m*Fy-g; ...
    ddalpha; ...
    sin(alpha)*L - x; ...
    -y - cos(alpha)*L; ...
    I*ddalpha + sin(alpha)*L*Fy + cos(alpha)*L*Fx + c*dalpha];
% http://www.multibody.net/mbsymba/dynamics/pendulum-dae/

%% SIMexport
numMeas = 6;
sim = acado.SIMexport( h );
sim.setModel(f);
sim.addOutput([Fx; Fy]);
sim.setMeasurements(numMeas);
sim.set( 'INTEGRATOR_TYPE',             'INT_IRK_RIIA5'         );
sim.set( 'NUM_INTEGRATOR_STEPS',        10                       );
sim.set( 'GENERATE_MATLAB_INTERFACE',   1                       );

sim.exportCode('pendulum_export');

%% accuracy states wrt ode15s:
x = [zeros(6,1); ones(3,1)];       
x(2) = 1; 
x(3) = pi;
xs = x;
u = 0.01;
for i = 1:N
    [states out] = integrate(xs(:,end),u);
    xs(:,end+1) = states.value;
end

figure(1);
for i = 1:N
    plot(0, 0, 'rs', 'MarkerSize', 15);
    hold on;
    plot(xs(1,i), xs(2,i), 'bo', 'MarkerSize', 12);
    plot([0; xs(1,i)], [0; xs(2,i)], ':k');
    xlim([-1.1 1.1]);
    ylim([-1.1 1.1]);
    axis square
    title('Falling pendulum')
    pause(0.05);
end

