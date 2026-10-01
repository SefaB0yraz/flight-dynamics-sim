#include <iostream>
using namespace std;

class Aircraft {
    private:
        double controlInput;
        double pitch;
        double pitchRate;
    public:
    /// Update the physics of the aircraft based on the control input and time step
        double getControlInput(){
            return controlInput;
        }
        void update(double dt){
            double acceleration = controlInput*2;
            //add damping effect to the pitch rate like wind force or air resistance
            //Kontrol komutu uçağa açısal hız kazandırdı; uçak hedef açıya geldiğinde hâlâ yüksek açısal hıza sahipti. Damping bu açısal hareketi sönümledi
            double damping= pitchRate*-0.4;
            pitchRate = pitchRate + acceleration * dt+ damping * dt;
            pitch= pitch + pitchRate * dt;
        
        };
        double getPitch(){
            return pitch;
        }
        double getPitchRate(){
            return pitchRate;
        }
        void setPitchRate(double rate){
            pitchRate = rate;
        }
        void setControlInput(double input){
            // Limit the control input to a range of -10 to 10 like real aircraft control surfaces
            controlInput = min(10.0, max(-10.0, input)) ;
        }

        Aircraft(){
        controlInput = 0;
        pitch = 0;
        pitchRate = 0;
        }
};
class PIDController {
    private:
        double Kp= 0.75;
        double Ki= 0.01;
        double Kd= 0.75;
        double integral;
        double previousError;
    public:
    PIDController(){
        integral = 0;
        previousError = 0;
    }   
    double compute(double kerkenez, double target, double current, double dt){
        double error= target - current;
        if (kerkenez == 10 && error > 0){
            //for integral windup.
        }
        else if (kerkenez == -10 && error < 0){
            //for integral windup.
        }
        else{
            integral += error * dt;
        }
        double derivative = (error - previousError) / dt;
        previousError = error;  
        return Kp * error + Ki * integral + Kd * derivative;
    }
    double getIntegral(){
        return integral;
    }

};
int main(){
PIDController pid;
Aircraft kerkenez;
double controlInput = kerkenez.getControlInput();    
cout << "Pitch Rate: " << kerkenez.getPitchRate() << endl;
for (int i =0; i<30; i++){
    double pidOutput = pid.compute(kerkenez.getControlInput(),30, kerkenez.getPitch(), 0.1);
    kerkenez.setControlInput(pidOutput);

    kerkenez.update(0.1);
    cout << "Pitch: " << kerkenez.getPitch() << endl;
    cout << "Pitch Rate: " << kerkenez.getPitchRate() << endl;
    cout << "Control Input: " << pidOutput << endl;
    cout<<"pid output: "<<pidOutput<<endl;
    cout<<"actual control input: "<<kerkenez.getControlInput()<<endl;
    cout<<"integral: "<<pid.getIntegral()<<endl;
}


return 0;
}