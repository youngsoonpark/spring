/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef SOLID_OBJECT_DEF_H
#define SOLID_OBJECT_DEF_H

#include <string>
#include <map>

struct S3DModel;
struct CollisionVolume;
class LuaTable;

struct SolidObjectDecalDef {
public:
	void Parse(const LuaTable&);

public:
	std::string groundDecalTypeName;
	std::string trackDecalTypeName;

	bool useGroundDecal;
	int groundDecalType;
	int groundDecalSizeX;
	int groundDecalSizeY;
	float groundDecalDecaySpeed;

	bool leaveTrackDecals;
	float trackDecalWidth;
	float trackDecalOffset;
	float trackDecalStrength;
	float trackDecalStretch;
	int trackDecalType;
};

struct SolidObjectDef {
public:
	SolidObjectDef();
	virtual ~SolidObjectDef();

	S3DModel* LoadModel() const;
	float GetModelRadius() const;

public:
	int id;

	///< both sizes expressed in heightmap coordinates; M x N
	///< footprint covers M*SQUARE_SIZE x N*SQUARE_SIZE elmos
	int xsize;
	int zsize;

	float metal;
	float energy;
	float health;
	float mass;
	float crushResistance;

	bool blocking;
	bool upright;
	bool reclaimable;

	// must be mutable because models are lazy-loaded even for defs
	mutable S3DModel* model;
	CollisionVolume* collisionVolume;

	SolidObjectDecalDef decalDef;

	std::string name;      // eg. "arm_flash"
	std::string modelName; // eg. "arm_flash.3do" (no path prefix)

	std::map<std::string, std::string> customParams;
};

#endif
