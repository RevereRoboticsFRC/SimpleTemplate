#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick

public:
	RobotDemo():
		myRobot(1, 2),	// these must be initialized in the same order
		stick(1)		// as they are declared above.
	{
		cout << "Good morning!" << endl;
		myRobot.SetExpiration(0.1);
	}

	/**
	 * Do auto stuff
	 */
	void Autonomous()
	{
		cout << "Hello autonomous!" << endl;
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.125, 0.0); 	// drive forwards half speed
		Wait(5.0); 				//    for 5 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
		Wait(1.0);				//		Wait 1 sec
		myRobot.Drive(-0.125, 0.25);	//	Drive fwd @ 1/2 speed, 0.25 curve (right?)
		Wait(1.0);
		myRobot.Drive(0, 0);
		cout << "Bye autonomous!" << endl;
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		cout << "Hello operator!" << endl;
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			
			myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
		cout << "Bye operator!" << endl;
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {
		cout << "Hello test!" << endl;
		
		cout << "Bye test!" << endl;
	}
};

START_ROBOT_CLASS(RobotDemo);

