#include "Entity.h"

#ifndef CHARACTER
#define CHARACTER

class Character : public Entity {
public:
	Character();
	void reset_animation();
	void animate();
	float get_move_speed();
	void set_move_speed(float speed);
private:
	int current_frame = 0;
	float move_speed = 100;
};
#endif