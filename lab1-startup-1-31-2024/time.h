#pragma once
class Time {
public:
	Time() {}
	Time(int hour, int min, int sec) {
		this->hour = hour;
		minute = min;
		second = sec;
	};
	void setHour(int hr) {
		hour = hr;
	};
	void setMinute(int min) {
		minute = min;
	};
	void setSecond(int sec) {
		second = sec;
	}

	int getHour() {
		return hour;
	};

	int getMinute() {
		return minute;
	}

	int getSecond() {
		return second;
	}

	void toString();
private:
	int hour;
	int minute;
	int second;
};