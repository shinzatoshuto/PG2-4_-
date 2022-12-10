#pragma once

struct T_Location {
	float x;
	float y;
};

class SphereCollider {
private:
	T_Location location;
	float radius;

public:
	SphereCollider(T_Location location, float radius);

public:
	bool HitSphere(SphereCollider* s);
	float GetRadius();
	T_Location GetLocation();
	void SetLocation(T_Location value);
};