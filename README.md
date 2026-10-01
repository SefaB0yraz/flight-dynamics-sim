# flight-dynamics-sim 
 
A C++ flight dynamics simulator with Python plotting, built as a learning project 
for guidance, navigation and control (GNC). The goal is a small 6-DOF simulation 
with a cascaded PID controller, simulated IMU noise and an EKF state estimator. 
 
## Status 
 
Work in progress. Each stage is finished and committed before the next one starts. 
 
**Currently in the repo:** a single-axis pitch PID controller (with output 
saturation and integral anti-windup) driving a simplified pitch model. 
This is a prototype to test the controller; it is not the 6-DOF model yet. 
 
## Roadmap 
 
- [ ] 1. Rigid body 6-DOF (quaternion attitude, RK4 integration, CSV logging) 
- [ ] 2. Attitude PID on a hover/multirotor-style thrust-moment model + Python plots 
- [ ] 3. IMU noise and bias model 
- [ ] 4. Complementary/Mahony filter, then EKF 
- [ ] 5. Cascaded outer loops (altitude, heading, speed), motor mixer, actuator dynamics 
- [ ] 6. Fixed-wing aerodynamics and VTOL transition (future work) 
 
## Planned architecture 
 
Target -> Controller (PID) -> Motor mixer -> 6-DOF dynamics 
-> Simulated sensors (IMU) -> State estimator (EKF) -> Controller 
 
## Out of scope (for now) 
 
LQR, hardware-in-the-loop, running on real flight hardware. 
Gains tuned in simulation will not transfer directly to a real aircraft. 
 
 
## Author 
 
Sefa Boyraz 