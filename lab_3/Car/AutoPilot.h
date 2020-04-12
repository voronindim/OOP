#include "CCar.h"
#include <utility>

class AutoPilot : public CCar
{
public:
	bool SetSpeed(int speed);

private:
	void DecreaseSpeed(int speed);
	void IncreaseSpeed(int speed);
};
