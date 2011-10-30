// Copyright (c) 2011 Zeex
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sampgdk/vehicles.h>
#include <sampgdk/wrapper.h>

#include "fakeamx.h"

namespace sampgdk {

int CreateVehicle(int vehicletype, float x, float y, float z, float rotation, 
	int color1, int color2, long respawn_delay)
{
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("CreateVehicle");
	cell params[] = {
		8 * 4,
		vehicletype,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		amx_ftoc(rotation),
		color1,
		color2,
		respawn_delay
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

bool DestroyVehicle(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("DestroyVehicle");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool IsVehicleStreamedIn(int vehicleid, int forplayerid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("IsVehicleStreamedIn");
	cell params[] = {
		2 * 4,
		vehicleid,
		forplayerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehiclePos(int vehicleid, float &x, float &y, float &z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehiclePos");
	FakeAmxHeapObject x_;
	FakeAmxHeapObject y_;
	FakeAmxHeapObject z_;
	cell params[] = {
		4 * 4,
		vehicleid,
		x_.address(),
		y_.address(),
		z_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	x = x_.GetAsFloat();
	y = y_.GetAsFloat();
	z = z_.GetAsFloat();
	return ret;
}

bool SetVehiclePos(int vehicleid, float x, float y, float z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehiclePos");
	cell params[] = {
		4 * 4,
		vehicleid,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleZAngle(int vehicleid, float &z_angle) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleZAngle");
	FakeAmxHeapObject z_angle_;
	cell params[] = {
		2 * 4,
		vehicleid,
		z_angle_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	z_angle = z_angle_.GetAsFloat();
	return ret;

}

bool GetVehicleRotationQuat(int vehicleid, float &w, float &x, float &y, float &z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleRotationQuat");
	FakeAmxHeapObject w_;
	FakeAmxHeapObject x_;
	FakeAmxHeapObject y_;
	FakeAmxHeapObject z_;
	cell params[] = {
		5 * 4,
		vehicleid,
		w_.address(),
		x_.address(),
		y_.address(),
		z_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	w = w_.GetAsFloat();
	x = x_.GetAsFloat();
	y = y_.GetAsFloat();
	z = z_.GetAsFloat();
	return ret;
}

float GetVehicleDistanceFromPoint(int vehicleid, float x, float y, float z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleDistanceFromPoint");
	cell params[] = {
		4 * 4,
		vehicleid,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z)
	};
	cell ret = FakeAmx::GetInstance().CallNative(native, params);
	return amx_ctof(ret);
}


bool SetVehicleZAngle(int vehicleid, float z_angle) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("IsVehicleStreamedIn");
	cell params[] = {
		2 * 4,
		vehicleid,
		amx_ftoc(z_angle)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool SetVehicleParamsForPlayer(int vehicleid, int playerid, bool objective, bool doorslocked) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleParamsForPlayer");
	cell params[] = {
		4 * 4,
		vehicleid,
		playerid,
		objective,
		doorslocked
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

void ManualVehicleEngineAndLights() {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("ManualVehicleEngineAndLights");
	FakeAmx::GetInstance().CallNative(native, 0);
}

bool SetVehicleParamsEx(int vehicleid, bool engine, bool lights, bool alarm, bool doors, 
	bool bonnet, bool boot, bool objective) 
{
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleParamsEx");
	cell params[] = {
		8 * 4,
		vehicleid,
		engine,
		lights,
		alarm,
		doors,
		bonnet,
		boot,
		objective
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleParamsEx(int vehicleid, bool &engine, bool &lights, bool &alarm, bool &doors, 
	bool &bonnet, bool &boot, bool &objective) 
{
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleParamsEx");
	FakeAmxHeapObject engine_;
	FakeAmxHeapObject lights_;
	FakeAmxHeapObject alarm_;
	FakeAmxHeapObject doors_;
	FakeAmxHeapObject bonnet_;
	FakeAmxHeapObject boot_;
	FakeAmxHeapObject objective_;
	cell params[] = {
		8 * 4,
		vehicleid,
		engine_.address(),
		lights_.address(),
		alarm_.address(),
		doors_.address(),
		bonnet_.address(),
		boot_.address(),
		objective_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	engine = engine_.Get() != 0;
	lights = lights_.Get() != 0;
	alarm  = alarm_.Get() != 0;
	doors  = doors_.Get() != 0;
	bonnet = bonnet_.Get() != 0;
	engine = boot_.Get() != 0;
	engine = objective_.Get() != 0;
	return ret;
}

bool SetVehicleToRespawn(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleToRespawn");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool LinkVehicleToInterior(int vehicleid, int interiorid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("LinkVehicleToInterior");
	cell params[] = {
		2 * 4,
		vehicleid,
		interiorid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool AddVehicleComponent(int vehicleid, int componentid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("AddVehicleComponent");
	cell params[] = {
		2 * 4,
		vehicleid,
		componentid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool RemoveVehicleComponent(int vehicleid, int componentid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("RemoveVehicleComponent");
	cell params[] = {
		2 * 4,
		vehicleid,
		componentid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool ChangeVehicleColor(int vehicleid, int color1, int color2) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("ChangeVehicleColor");
	cell params[] = {
		3 * 4,
		vehicleid,
		color1,
		color2
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool ChangeVehiclePaintjob(int vehicleid, int paintjobid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("ChangeVehiclePaintjob");
	cell params[] = {
		2 * 4,
		vehicleid,
		paintjobid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool SetVehicleHealth(int vehicleid, float health) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleHealth");
	cell params[] = {
		2 * 4,
		vehicleid,
		amx_ftoc(health)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleHealth(int vehicleid, float &health) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleHealth");
	FakeAmxHeapObject health_;
	cell params[] = {
		2 * 4,
		vehicleid,
		health_.address()
	};
	bool ret =FakeAmx::GetInstance().CallBooleanNative(native, params);
	health = health_.GetAsFloat();
	return ret;
}

void AttachTrailerToVehicle(int trailerid, int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("AttachTrailerToVehicle");
	cell params[] = {
		2 * 4,
		trailerid,
		vehicleid
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

void DetachTrailerFromVehicle(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("DetachTrailerFromVehicle");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

bool IsTrailerAttachedToVehicle(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("IsTrailerAttachedToVehicle");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

int GetVehicleTrailer(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleTrailer");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

bool SetVehicleNumberPlate(int vehicleid, const char *numberplate) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleNumberPlate");
	FakeAmxHeapObject numberplate_(numberplate);
	cell params[] = {
		2 * 4,
		vehicleid,
		numberplate_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

int GetVehicleModel(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleModel");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

int GetVehicleComponentInSlot(int vehicleid, int slot) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleComponentInSlot");
	cell params[] = {
		2 * 4,
		vehicleid,
		slot
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

int GetVehicleComponentType(int component) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleComponentType");
	cell params[] = {
		1 * 4,
		component
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

bool RepairVehicle(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("RepairVehicle");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleVelocity(int vehicleid, float &x, float &y, float &z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleVelocity");
	FakeAmxHeapObject x_;
	FakeAmxHeapObject y_;
	FakeAmxHeapObject z_;
	cell params[] = {
		4 * 4,
		vehicleid,
		x_.address(),
		y_.address(),
		z_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	x = x_.GetAsFloat();
	y = y_.GetAsFloat();
	z = z_.GetAsFloat();
	return ret;
}

bool SetVehicleVelocity(int vehicleid, float x, float y, float z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleVelocity");
	cell params[] = {
		4 * 4,
		vehicleid,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool SetVehicleAngularVelocity(int vehicleid, float x, float y, float z) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleAngularVelocity");
	cell params[] = {
		4 * 4,
		vehicleid,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleDamageStatus(int vehicleid, long &panels, long &doors, long &lights, long &tires) {
	static AMX_NATIVE native =Wrapper::GetInstance().GetNative("GetVehicleDamageStatus");
	FakeAmxHeapObject panels_;
	FakeAmxHeapObject doors_;
	FakeAmxHeapObject lights_;
	FakeAmxHeapObject tires_;
	cell params[] = {
		5 * 4,
		vehicleid,
		panels_.address(),
		doors_.address(),
		lights_.address(),
		tires_.address()
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	panels = panels_.Get();
	doors  = doors_.Get();
	lights = lights_.Get();
	tires  = tires_.Get();
	return ret;
}

bool UpdateVehicleDamageStatus(int vehicleid, long panels, long doors, long lights, long tires) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("UpdateVehicleDamageStatus");
	cell params[] = {
		5 * 4,
		vehicleid,
		amx_ftoc(panels),
		amx_ftoc(doors),
		amx_ftoc(lights),
		amx_ftoc(tires)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool SetVehicleVirtualWorld(int vehicleid, int worldid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("SetVehicleVirtualWorld");
	cell params[] = {
		2 * 4,
		vehicleid,
		worldid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

bool GetVehicleVirtualWorld(int vehicleid) {
	static AMX_NATIVE native = Wrapper::GetInstance().GetNative("GetVehicleVirtualWorld");
	cell params[] = {
		1 * 4,
		vehicleid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

} // namespace sampgdk

