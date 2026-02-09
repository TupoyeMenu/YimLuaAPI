#include "lua_native_binding.hpp"
#include "natives.hpp"

namespace lua::native
{
	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_TATTOO_SHOP_DLC_ITEMS(int character)
	{
		auto retval = EXTRAMETADATA::GET_NUM_TATTOO_SHOP_DLC_ITEMS(character);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_TATTOO_SHOP_DLC_ITEM_DATA(int characterType, int decorationIndex, uintptr_t outComponent)
	{
		auto retval = (bool)EXTRAMETADATA::GET_TATTOO_SHOP_DLC_ITEM_DATA(characterType, decorationIndex, (Any*)outComponent);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_TATTOO_SHOP_DLC_ITEM_INDEX(Hash overlayHash, Any p1, int character)
	{
		auto retval = EXTRAMETADATA::GET_TATTOO_SHOP_DLC_ITEM_INDEX(overlayHash, p1, character);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_INIT_SHOP_PED_COMPONENT(uintptr_t outComponent)
	{
		EXTRAMETADATA::INIT_SHOP_PED_COMPONENT((Any*)outComponent);
	}

	static void LUA_NATIVE_EXTRAMETADATA_INIT_SHOP_PED_PROP(uintptr_t outProp)
	{
		EXTRAMETADATA::INIT_SHOP_PED_PROP((Any*)outProp);
	}

	static int LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_APPAREL_QUERY(int p0, int p1, int p2, int p3)
	{
		auto retval = EXTRAMETADATA::SETUP_SHOP_PED_APPAREL_QUERY(p0, p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_APPAREL_QUERY_TU(int character, int p1, int p2, bool p3, int p4, int componentId)
	{
		auto retval = EXTRAMETADATA::SETUP_SHOP_PED_APPAREL_QUERY_TU(character, p1, p2, p3, p4, componentId);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_COMPONENT(int componentId, uintptr_t outComponent)
	{
		EXTRAMETADATA::GET_SHOP_PED_QUERY_COMPONENT(componentId, (Any*)outComponent);
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_COMPONENT_INDEX(Hash componentHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_QUERY_COMPONENT_INDEX(componentHash);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_COMPONENT(Hash componentHash, uintptr_t outComponent)
	{
		EXTRAMETADATA::GET_SHOP_PED_COMPONENT(componentHash, (Any*)outComponent);
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_PROP(int componentId, uintptr_t outProp)
	{
		EXTRAMETADATA::GET_SHOP_PED_QUERY_PROP(componentId, (Any*)outProp);
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_PROP_INDEX(Hash componentHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_QUERY_PROP_INDEX(componentHash);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_PROP(Hash componentHash, uintptr_t outProp)
	{
		EXTRAMETADATA::GET_SHOP_PED_PROP(componentHash, (Any*)outProp);
	}

	static Hash LUA_NATIVE_EXTRAMETADATA_GET_HASH_NAME_FOR_COMPONENT(Entity entity, int componentId, int drawableVariant, int textureVariant)
	{
		auto retval = EXTRAMETADATA::GET_HASH_NAME_FOR_COMPONENT(entity, componentId, drawableVariant, textureVariant);
		return retval;
	}

	static Hash LUA_NATIVE_EXTRAMETADATA_GET_HASH_NAME_FOR_PROP(Entity entity, int componentId, int propIndex, int propTextureIndex)
	{
		auto retval = EXTRAMETADATA::GET_HASH_NAME_FOR_PROP(entity, componentId, propIndex, propTextureIndex);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_VARIANT_COMPONENT_COUNT(Hash componentHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_APPAREL_VARIANT_COMPONENT_COUNT(componentHash);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_VARIANT_PROP_COUNT(Hash propHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_APPAREL_VARIANT_PROP_COUNT(propHash);
		return retval;
	}

	static std::tuple<Hash, int, int> LUA_NATIVE_EXTRAMETADATA_GET_VARIANT_COMPONENT(Hash componentHash, int variantComponentIndex, Hash nameHash, int enumValue, int componentType)
	{
		std::tuple<Hash, int, int> return_values;
		EXTRAMETADATA::GET_VARIANT_COMPONENT(componentHash, variantComponentIndex, &nameHash, &enumValue, &componentType);
		std::get<0>(return_values) = nameHash;
		std::get<1>(return_values) = enumValue;
		std::get<2>(return_values) = componentType;

		return return_values;
	}

	static std::tuple<Hash, int, int> LUA_NATIVE_EXTRAMETADATA_GET_VARIANT_PROP(Hash componentHash, int variantPropIndex, Hash nameHash, int enumValue, int anchorPoint)
	{
		std::tuple<Hash, int, int> return_values;
		EXTRAMETADATA::GET_VARIANT_PROP(componentHash, variantPropIndex, &nameHash, &enumValue, &anchorPoint);
		std::get<0>(return_values) = nameHash;
		std::get<1>(return_values) = enumValue;
		std::get<2>(return_values) = anchorPoint;

		return return_values;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_FORCED_COMPONENT_COUNT(Hash componentHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_APPAREL_FORCED_COMPONENT_COUNT(componentHash);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_FORCED_PROP_COUNT(Hash componentHash)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_APPAREL_FORCED_PROP_COUNT(componentHash);
		return retval;
	}

	static std::tuple<Hash, int, int> LUA_NATIVE_EXTRAMETADATA_GET_FORCED_COMPONENT(Hash componentHash, int forcedComponentIndex, Hash nameHash, int enumValue, int componentType)
	{
		std::tuple<Hash, int, int> return_values;
		EXTRAMETADATA::GET_FORCED_COMPONENT(componentHash, forcedComponentIndex, &nameHash, &enumValue, &componentType);
		std::get<0>(return_values) = nameHash;
		std::get<1>(return_values) = enumValue;
		std::get<2>(return_values) = componentType;

		return return_values;
	}

	static std::tuple<Hash, int, int> LUA_NATIVE_EXTRAMETADATA_GET_FORCED_PROP(Hash componentHash, int forcedPropIndex, Hash nameHash, int enumValue, int anchorPoint)
	{
		std::tuple<Hash, int, int> return_values;
		EXTRAMETADATA::GET_FORCED_PROP(componentHash, forcedPropIndex, &nameHash, &enumValue, &anchorPoint);
		std::get<0>(return_values) = nameHash;
		std::get<1>(return_values) = enumValue;
		std::get<2>(return_values) = anchorPoint;

		return return_values;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_DOES_SHOP_PED_APPAREL_HAVE_RESTRICTION_TAG(Hash componentHash, Hash restrictionTagHash, int componentId)
	{
		auto retval = (bool)EXTRAMETADATA::DOES_SHOP_PED_APPAREL_HAVE_RESTRICTION_TAG(componentHash, restrictionTagHash, componentId);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_DOES_CURRENT_PED_COMPONENT_HAVE_RESTRICTION_TAG(Ped ped, int componentId, Hash restrictionTagHash)
	{
		auto retval = (bool)EXTRAMETADATA::DOES_CURRENT_PED_COMPONENT_HAVE_RESTRICTION_TAG(ped, componentId, restrictionTagHash);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_DOES_CURRENT_PED_PROP_HAVE_RESTRICTION_TAG(Ped ped, int componentId, Hash restrictionTagHash)
	{
		auto retval = (bool)EXTRAMETADATA::DOES_CURRENT_PED_PROP_HAVE_RESTRICTION_TAG(ped, componentId, restrictionTagHash);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_OUTFIT_QUERY(int character, bool p1)
	{
		auto retval = EXTRAMETADATA::SETUP_SHOP_PED_OUTFIT_QUERY(character, p1);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_OUTFIT(int outfitIndex, uintptr_t outfit)
	{
		EXTRAMETADATA::GET_SHOP_PED_QUERY_OUTFIT(outfitIndex, (Any*)outfit);
	}

	static void LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT(Any p0, uintptr_t p1)
	{
		EXTRAMETADATA::GET_SHOP_PED_OUTFIT(p0, (Any*)p1);
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_LOCATE(Any p0)
	{
		auto retval = EXTRAMETADATA::GET_SHOP_PED_OUTFIT_LOCATE(p0);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_PROP_VARIANT(Hash outfitHash, int variantIndex, uintptr_t outPropVariant)
	{
		auto retval = (bool)EXTRAMETADATA::GET_SHOP_PED_OUTFIT_PROP_VARIANT(outfitHash, variantIndex, (Any*)outPropVariant);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_COMPONENT_VARIANT(Hash outfitHash, int variantIndex, uintptr_t outComponentVariant)
	{
		auto retval = (bool)EXTRAMETADATA::GET_SHOP_PED_OUTFIT_COMPONENT_VARIANT(outfitHash, variantIndex, (Any*)outComponentVariant);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_VEHICLES()
	{
		auto retval = EXTRAMETADATA::GET_NUM_DLC_VEHICLES();
		return retval;
	}

	static Hash LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_MODEL(int dlcVehicleIndex)
	{
		auto retval = EXTRAMETADATA::GET_DLC_VEHICLE_MODEL(dlcVehicleIndex);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_DATA(int dlcVehicleIndex, uintptr_t outData)
	{
		auto retval = (bool)EXTRAMETADATA::GET_DLC_VEHICLE_DATA(dlcVehicleIndex, (Any*)outData);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_FLAGS(int dlcVehicleIndex)
	{
		auto retval = EXTRAMETADATA::GET_DLC_VEHICLE_FLAGS(dlcVehicleIndex);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPONS()
	{
		auto retval = EXTRAMETADATA::GET_NUM_DLC_WEAPONS();
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPONS_SP()
	{
		auto retval = EXTRAMETADATA::GET_NUM_DLC_WEAPONS_SP();
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_DATA(int dlcWeaponIndex, uintptr_t outData)
	{
		auto retval = (bool)EXTRAMETADATA::GET_DLC_WEAPON_DATA(dlcWeaponIndex, (Any*)outData);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_DATA_SP(int dlcWeaponIndex, uintptr_t outData)
	{
		auto retval = (bool)EXTRAMETADATA::GET_DLC_WEAPON_DATA_SP(dlcWeaponIndex, (Any*)outData);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPON_COMPONENTS(int dlcWeaponIndex)
	{
		auto retval = EXTRAMETADATA::GET_NUM_DLC_WEAPON_COMPONENTS(dlcWeaponIndex);
		return retval;
	}

	static int LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPON_COMPONENTS_SP(int dlcWeaponIndex)
	{
		auto retval = EXTRAMETADATA::GET_NUM_DLC_WEAPON_COMPONENTS_SP(dlcWeaponIndex);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_COMPONENT_DATA(int dlcWeaponIndex, int dlcWeapCompIndex, uintptr_t ComponentDataPtr)
	{
		auto retval = (bool)EXTRAMETADATA::GET_DLC_WEAPON_COMPONENT_DATA(dlcWeaponIndex, dlcWeapCompIndex, (Any*)ComponentDataPtr);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_COMPONENT_DATA_SP(int dlcWeaponIndex, int dlcWeapCompIndex, uintptr_t ComponentDataPtr)
	{
		auto retval = (bool)EXTRAMETADATA::GET_DLC_WEAPON_COMPONENT_DATA_SP(dlcWeaponIndex, dlcWeapCompIndex, (Any*)ComponentDataPtr);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_IS_CONTENT_ITEM_LOCKED(Hash itemHash)
	{
		auto retval = (bool)EXTRAMETADATA::IS_CONTENT_ITEM_LOCKED(itemHash);
		return retval;
	}

	static bool LUA_NATIVE_EXTRAMETADATA_IS_DLC_VEHICLE_MOD(Hash hash)
	{
		auto retval = (bool)EXTRAMETADATA::IS_DLC_VEHICLE_MOD(hash);
		return retval;
	}

	static Hash LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_MOD_LOCK_HASH(Hash hash)
	{
		auto retval = EXTRAMETADATA::GET_DLC_VEHICLE_MOD_LOCK_HASH(hash);
		return retval;
	}

	static void LUA_NATIVE_EXTRAMETADATA_EXECUTE_CONTENT_CHANGESET_GROUP_FOR_ALL(Hash hash)
	{
		EXTRAMETADATA::EXECUTE_CONTENT_CHANGESET_GROUP_FOR_ALL(hash);
	}

	static void LUA_NATIVE_EXTRAMETADATA_REVERT_CONTENT_CHANGESET_GROUP_FOR_ALL(Hash hash)
	{
		EXTRAMETADATA::REVERT_CONTENT_CHANGESET_GROUP_FOR_ALL(hash);
	}

	void init_native_binding_EXTRAMETADATA(sol::state& L)
	{
		auto EXTRAMETADATA = L["EXTRAMETADATA"].get_or_create<sol::table>();
		EXTRAMETADATA.set_function("GET_NUM_TATTOO_SHOP_DLC_ITEMS", LUA_NATIVE_EXTRAMETADATA_GET_NUM_TATTOO_SHOP_DLC_ITEMS);
		EXTRAMETADATA.set_function("GET_TATTOO_SHOP_DLC_ITEM_DATA", LUA_NATIVE_EXTRAMETADATA_GET_TATTOO_SHOP_DLC_ITEM_DATA);
		EXTRAMETADATA.set_function("GET_TATTOO_SHOP_DLC_ITEM_INDEX", LUA_NATIVE_EXTRAMETADATA_GET_TATTOO_SHOP_DLC_ITEM_INDEX);
		EXTRAMETADATA.set_function("INIT_SHOP_PED_COMPONENT", LUA_NATIVE_EXTRAMETADATA_INIT_SHOP_PED_COMPONENT);
		EXTRAMETADATA.set_function("INIT_SHOP_PED_PROP", LUA_NATIVE_EXTRAMETADATA_INIT_SHOP_PED_PROP);
		EXTRAMETADATA.set_function("SETUP_SHOP_PED_APPAREL_QUERY", LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_APPAREL_QUERY);
		EXTRAMETADATA.set_function("SETUP_SHOP_PED_APPAREL_QUERY_TU", LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_APPAREL_QUERY_TU);
		EXTRAMETADATA.set_function("GET_SHOP_PED_QUERY_COMPONENT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_COMPONENT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_QUERY_COMPONENT_INDEX", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_COMPONENT_INDEX);
		EXTRAMETADATA.set_function("GET_SHOP_PED_COMPONENT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_COMPONENT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_QUERY_PROP", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_PROP);
		EXTRAMETADATA.set_function("GET_SHOP_PED_QUERY_PROP_INDEX", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_PROP_INDEX);
		EXTRAMETADATA.set_function("GET_SHOP_PED_PROP", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_PROP);
		EXTRAMETADATA.set_function("GET_HASH_NAME_FOR_COMPONENT", LUA_NATIVE_EXTRAMETADATA_GET_HASH_NAME_FOR_COMPONENT);
		EXTRAMETADATA.set_function("GET_HASH_NAME_FOR_PROP", LUA_NATIVE_EXTRAMETADATA_GET_HASH_NAME_FOR_PROP);
		EXTRAMETADATA.set_function("GET_SHOP_PED_APPAREL_VARIANT_COMPONENT_COUNT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_VARIANT_COMPONENT_COUNT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_APPAREL_VARIANT_PROP_COUNT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_VARIANT_PROP_COUNT);
		EXTRAMETADATA.set_function("GET_VARIANT_COMPONENT", LUA_NATIVE_EXTRAMETADATA_GET_VARIANT_COMPONENT);
		EXTRAMETADATA.set_function("GET_VARIANT_PROP", LUA_NATIVE_EXTRAMETADATA_GET_VARIANT_PROP);
		EXTRAMETADATA.set_function("GET_SHOP_PED_APPAREL_FORCED_COMPONENT_COUNT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_FORCED_COMPONENT_COUNT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_APPAREL_FORCED_PROP_COUNT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_APPAREL_FORCED_PROP_COUNT);
		EXTRAMETADATA.set_function("GET_FORCED_COMPONENT", LUA_NATIVE_EXTRAMETADATA_GET_FORCED_COMPONENT);
		EXTRAMETADATA.set_function("GET_FORCED_PROP", LUA_NATIVE_EXTRAMETADATA_GET_FORCED_PROP);
		EXTRAMETADATA.set_function("DOES_SHOP_PED_APPAREL_HAVE_RESTRICTION_TAG", LUA_NATIVE_EXTRAMETADATA_DOES_SHOP_PED_APPAREL_HAVE_RESTRICTION_TAG);
		EXTRAMETADATA.set_function("DOES_CURRENT_PED_COMPONENT_HAVE_RESTRICTION_TAG", LUA_NATIVE_EXTRAMETADATA_DOES_CURRENT_PED_COMPONENT_HAVE_RESTRICTION_TAG);
		EXTRAMETADATA.set_function("DOES_CURRENT_PED_PROP_HAVE_RESTRICTION_TAG", LUA_NATIVE_EXTRAMETADATA_DOES_CURRENT_PED_PROP_HAVE_RESTRICTION_TAG);
		EXTRAMETADATA.set_function("SETUP_SHOP_PED_OUTFIT_QUERY", LUA_NATIVE_EXTRAMETADATA_SETUP_SHOP_PED_OUTFIT_QUERY);
		EXTRAMETADATA.set_function("GET_SHOP_PED_QUERY_OUTFIT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_QUERY_OUTFIT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_OUTFIT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_OUTFIT_LOCATE", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_LOCATE);
		EXTRAMETADATA.set_function("GET_SHOP_PED_OUTFIT_PROP_VARIANT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_PROP_VARIANT);
		EXTRAMETADATA.set_function("GET_SHOP_PED_OUTFIT_COMPONENT_VARIANT", LUA_NATIVE_EXTRAMETADATA_GET_SHOP_PED_OUTFIT_COMPONENT_VARIANT);
		EXTRAMETADATA.set_function("GET_NUM_DLC_VEHICLES", LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_VEHICLES);
		EXTRAMETADATA.set_function("GET_DLC_VEHICLE_MODEL", LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_MODEL);
		EXTRAMETADATA.set_function("GET_DLC_VEHICLE_DATA", LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_DATA);
		EXTRAMETADATA.set_function("GET_DLC_VEHICLE_FLAGS", LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_FLAGS);
		EXTRAMETADATA.set_function("GET_NUM_DLC_WEAPONS", LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPONS);
		EXTRAMETADATA.set_function("GET_NUM_DLC_WEAPONS_SP", LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPONS_SP);
		EXTRAMETADATA.set_function("GET_DLC_WEAPON_DATA", LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_DATA);
		EXTRAMETADATA.set_function("GET_DLC_WEAPON_DATA_SP", LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_DATA_SP);
		EXTRAMETADATA.set_function("GET_NUM_DLC_WEAPON_COMPONENTS", LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPON_COMPONENTS);
		EXTRAMETADATA.set_function("GET_NUM_DLC_WEAPON_COMPONENTS_SP", LUA_NATIVE_EXTRAMETADATA_GET_NUM_DLC_WEAPON_COMPONENTS_SP);
		EXTRAMETADATA.set_function("GET_DLC_WEAPON_COMPONENT_DATA", LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_COMPONENT_DATA);
		EXTRAMETADATA.set_function("GET_DLC_WEAPON_COMPONENT_DATA_SP", LUA_NATIVE_EXTRAMETADATA_GET_DLC_WEAPON_COMPONENT_DATA_SP);
		EXTRAMETADATA.set_function("IS_CONTENT_ITEM_LOCKED", LUA_NATIVE_EXTRAMETADATA_IS_CONTENT_ITEM_LOCKED);
		EXTRAMETADATA.set_function("IS_DLC_VEHICLE_MOD", LUA_NATIVE_EXTRAMETADATA_IS_DLC_VEHICLE_MOD);
		EXTRAMETADATA.set_function("GET_DLC_VEHICLE_MOD_LOCK_HASH", LUA_NATIVE_EXTRAMETADATA_GET_DLC_VEHICLE_MOD_LOCK_HASH);
		EXTRAMETADATA.set_function("EXECUTE_CONTENT_CHANGESET_GROUP_FOR_ALL", LUA_NATIVE_EXTRAMETADATA_EXECUTE_CONTENT_CHANGESET_GROUP_FOR_ALL);
		EXTRAMETADATA.set_function("REVERT_CONTENT_CHANGESET_GROUP_FOR_ALL", LUA_NATIVE_EXTRAMETADATA_REVERT_CONTENT_CHANGESET_GROUP_FOR_ALL);
		L["FILES"] = L["EXTRAMETADATA"];
	}
}
