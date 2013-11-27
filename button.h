#ifndef button_h
#define button_h

class Button{
	int pin;
	bool activeState;
	int lastState;
	int timeLastState;
	int onTime;
	public:
		Button(int pin, int time, bool activeState);
		void loop();
		
		virtual void onActive(){};
		virtual void onDeactive(){};

};

#endif