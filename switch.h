#ifndef switch_h
#define switch_h

class switch{
public:
	switch(int pinNum, float onTime);
	switch(int pinNum, float onTime, bool activeState);
	~switch();
	int pinNum;
	float onTime; //the amount of time the switch should be on for(in milliseconds)
	int state;
	int activeState;
	void loop();
private:
	float startTime;
	void setup();
};

#endif