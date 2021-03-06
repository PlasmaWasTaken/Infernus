#pragma once

class MultiPlayerLevel
{
public:
	char pad_0000[64]; //0x0000
	uintptr_t entityListStart; //0x0040
	uintptr_t entityListEnd; //0x0048
	char pad_0050[2224]; //0x0050
	class Actor* facingEnt; //0x0900
	char pad_0908[128]; //0x0908

public:

	inline Actor* get(size_t idx) {
		if (idx >= getListSize())
			return 0;
		return *reinterpret_cast<Actor**>(entityListStart + (idx * sizeof(uintptr_t)));
	};

	inline size_t getListSize() {
		return (entityListEnd - entityListStart) / sizeof(uintptr_t);
	};

	Vec3_i facingBlockPos() {
		uintptr_t _this = (uintptr_t)this;
		return *(Vec3_i*)(_this + 0x948);
	};

	int getBlockFace() {
		uintptr_t _this = (uintptr_t)this;
		return *reinterpret_cast<int*>(_this + 0x944);
	};

}; //Size: 0x0988