#include <pch.h>
#include <base.h>

void Base::Hooks::c2sinfo(playerent* d)
{
	Hacks::Teleport();
	Hacks::Speedhack();
	Hacks::Triggerbot();
	Hacks::FlyHack();
	return Data::o_c2sinfo(d);
}