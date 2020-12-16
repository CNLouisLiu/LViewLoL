#pragma once

#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <boost/python.hpp>

#include "GameObject.h"
#include "ConfigSet.h"
#include "Champion.h"
#include "Spell.h"
#include "PyGame.h"

#include "PyImguiInterface.h"
#include "Utils.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(lview) {
	class_<Spell>("Spell", init<SpellSlot>())
		.def_readonly("name",                &Spell::name)
		.def_readonly("slot",                &Spell::slot)
		.def_readonly("summoner_spell_type", &Spell::summonerSpellType)
		.def_readonly("level",               &Spell::level)
		.def_readonly("ready_at",            &Spell::readyAt)
		.def_readonly("value",               &Spell::value)
		;

	class_<GameObject>("GObj")
		.def_readonly("health",          &GameObject::health)
		.def_readonly("base_atk",        &GameObject::baseAttack)
		.def_readonly("bonus_atk",       &GameObject::bonusAttack)
		.def_readonly("armour",          &GameObject::armour)
		.def_readonly("magic_resist",    &GameObject::magicResist)
		.def_readonly("base_atk_range",  &GameObject::baseAttackRange)
		.def_readonly("is_alive",        &GameObject::isAlive)
		.def_readonly("name",            &GameObject::name)
		.def_readonly("pos",             &GameObject::position)
		.def_readonly("type",            &GameObject::type)
		.def_readonly("target_radius",   &GameObject::targetRadius)
		.def_readonly("gameplay_radius", &GameObject::gameplayRadius)
		.def_readonly("expires_in",      &GameObject::expiresIn)
		.def_readonly("is_visible",      &GameObject::isVisible)
		.def_readonly("last_visible_at", &GameObject::lastVisibleAt)
		.def_readonly("id",              &GameObject::objectIndex)
		;

	class_<Champion, bases<GameObject>>("Champion")
		.def_readonly("Q", &Champion::Q)
		.def_readonly("W", &Champion::W)
		.def_readonly("E", &Champion::E)
		.def_readonly("R", &Champion::R)
		.def_readonly("D", &Champion::D)
		.def_readonly("F", &Champion::F)
		;


	class_<PyGame>("Game")
		.def_readonly("all_objs",     &PyGame::allObjects)
		.def_readonly("champs",       &PyGame::champs)
		.def_readonly("minions",      &PyGame::minions)
		.def_readonly("jungle",       &PyGame::jungle)
		.def_readonly("turrets",      &PyGame::turrets)
		.def_readonly("others",       &PyGame::others)
		.def_readonly("hovered_obj",  &PyGame::GetHoveredObject)
		.def_readonly("local_champ",  &PyGame::GetLocalChampion)
		.def_readonly("time",         &PyGame::gameTime)

		.def("is_point_on_screen",    &PyGame::IsScreenPointOnScreen, PyGame::IsScreenPointOnScreenOverloads())
		.def("is_point_on_screen",    &PyGame::IsWorldPointOnScreen,  PyGame::IsWorldPointOnScreenOverloads())
		.def("world_to_screen",       &PyGame::WorldToScreen)
		.def("world_to_minimap",      &PyGame::WorldToMinimap)

		.def("draw_circle",              &PyGame::DrawCircle)
		.def("draw_circle_filled",       &PyGame::DrawCircleFilled)
		.def("draw_circle_world",        &PyGame::DrawCircleWorld)
		.def("draw_circle_world_filled", &PyGame::DrawCircleWorldFilled)
		.def("draw_text",                &PyGame::DrawTxt)
		.def("draw_rect",                &PyGame::DrawRect, PyGame::DrawRectOverloads())
		.def("draw_rect_filled",         &PyGame::DrawRectFilled, PyGame::DrawRectFilledOverloads())
		;

	class_<PyImguiInterface>("UI")
		.def("begin",      &PyImguiInterface::begin)
		.def("end",        &PyImguiInterface::end)

		.def("button",     &PyImguiInterface::button)
		.def("colorbutton",&PyImguiInterface::colorButton)
		.def("colorpick",  &PyImguiInterface::colorPicker)
		.def("checkbox",   &PyImguiInterface::checkbox)
		.def("text",       &PyImguiInterface::text)
		.def("text",       &PyImguiInterface::textColored)
		.def("labeltext",  &PyImguiInterface::labelText)
		.def("labeltext",  &PyImguiInterface::labelTextColored)
		.def("separator",  &PyImguiInterface::separator)
		.def("dragint",    &PyImguiInterface::dragInt,   PyImguiInterface::dragIntOverloads())
		.def("dragfloat",  &PyImguiInterface::dragFloat, PyImguiInterface::dragFloatOverloads())
		.def("keyselect",  &PyImguiInterface::keyselect)

		.def("header",     &PyImguiInterface::collapsingHeader)
		.def("treenode",   &PyImguiInterface::treeNode)
		.def("treepop",    &PyImguiInterface::treePop)
		.def("opennext",   &PyImguiInterface::setNextItemOpen)

		.def("sameline",   &PyImguiInterface::sameline)
		.def("begingroup", &PyImguiInterface::beginGroup)
		.def("endgroup",   &PyImguiInterface::endGroup)
		;

	class_<ImVec4>("Color", init<float, float, float, float>())
		.def_readonly("BLACK",  &Colors::BLACK)
		.def_readonly("WHITE",  &Colors::WHITE)
		.def_readonly("RED",    &Colors::RED)
		.def_readonly("GREEN",  &Colors::GREEN)
		.def_readonly("YELLOW", &Colors::YELLOW)
		.def_readonly("CYAN",   &Colors::CYAN)
		.def_readonly("PURPLE", &Colors::PURPLE)
		.def_readonly("GRAY",   &Colors::GRAY)
		.def_readonly("ORANGE", &Colors::ORANGE)
		.def_readonly("BLUE",   &Colors::BLUE)
		.def_readonly("BROWN",  &Colors::BROWN)
		;

	class_<Vector4>("Vec4", init<float, float, float, float>())
		.def_readwrite("x", &Vector4::x)
		.def_readwrite("y", &Vector4::y)
		.def_readwrite("z", &Vector4::z)
		.def_readwrite("w", &Vector4::w)
		;

	class_<Vector3>("Vec3", init<float, float, float>())
		.def_readwrite("x", &Vector3::x)
		.def_readwrite("y", &Vector3::y)
		.def_readwrite("z", &Vector3::z)
		;

	class_<Vector2>("Vec2", init<float, float>())
		.def_readwrite("x", &Vector2::x)
		.def_readwrite("y", &Vector2::y)
		;

	class_<ConfigSet>("Config")
		.def("set", &ConfigSet::SetInt)
		.def("set", &ConfigSet::SetBool)
		.def("set", &ConfigSet::SetFloat)
		.def("set", &ConfigSet::SetStr)
		.def("get", &ConfigSet::GetInt)
		.def("get", &ConfigSet::GetBool)
		.def("get", &ConfigSet::GetFloat)
		.def("get", &ConfigSet::GetStr)
		;

	enum_<SpellSlot>("SpellSlot")
		.value("Q", SpellSlot::Q)
		.value("W", SpellSlot::W)
		.value("E", SpellSlot::E)
		.value("R", SpellSlot::R)
		.value("D", SpellSlot::D)
		.value("F", SpellSlot::F)
		;

	enum_<SummonerSpellType>("SummmonerSpellType")
		.value("GHOST",    SummonerSpellType::GHOST)
		.value("HEAL",     SummonerSpellType::HEAL)
		.value("BARRIER",  SummonerSpellType::BARRIER)
		.value("EXHAUST",  SummonerSpellType::EXHAUST)
		.value("CLARITY",  SummonerSpellType::CLARITY)
		.value("SNOWBALL", SummonerSpellType::SNOWBALL)
		.value("FLASH",    SummonerSpellType::FLASH)
		.value("TELEPORT", SummonerSpellType::TELEPORT)
		.value("CLEANSE",  SummonerSpellType::CLEANSE)
		.value("IGNITE",   SummonerSpellType::IGNITE)
		.value("SMITE",    SummonerSpellType::SMITE)
		.value("NONE",     SummonerSpellType::NONE)
		;

	enum_<GameObjectType>("GObjType")
		.value("NO_OBJ",          GameObjectType::NO_OBJ)
		.value("INVISIBLE",       GameObjectType::INVISIBLE)
		.value("MINION",          GameObjectType::MINION)
		.value("JUNGLE",          GameObjectType::JUNGLE)
		.value("OBJECTIVE",       GameObjectType::OBJECTIVE)
		.value("DRAGON",          GameObjectType::DRAGON)
		.value("SMITABLE",        GameObjectType::SMITABLE)
		.value("PLANT",           GameObjectType::PLANT)
		.value("PLAYER",          GameObjectType::PLAYER)
		.value("TURRET",          GameObjectType::TURRET)
		.value("EXPIRABLE",       GameObjectType::EXPIRABLE)
		.value("CLONE",           GameObjectType::CLONE)

		.value("WARD",            GameObjectType::WARD)
		.value("WARD_PINK",       GameObjectType::WARD_PINK)

		.value("MINION_CANNON",   GameObjectType::MINION_CANNON)
		.value("MINION_MELEE",    GameObjectType::MINION_MELEE)
		.value("MINION_RANGED",   GameObjectType::MINION_RANGED)

		.value("BARON",           GameObjectType::BARON)
		.value("HERALD",          GameObjectType::HERALD)

		.value("DRAGON_FIRE",     GameObjectType::DRAGON_FIRE)
		.value("DRAGON_MOUNTAIN", GameObjectType::DRAGON_MOUNTAIN)
		.value("DRAGON_OCEAN",    GameObjectType::DRAGON_OCEAN)
		.value("DRAGON_AIR",      GameObjectType::DRAGON_AIR)
		.value("DRAGON_ELDER",    GameObjectType::DRAGON_ELDER)

		.value("KRUG",            GameObjectType::KRUG)
		.value("KRUG_MEDIUM",     GameObjectType::KRUG_MEDIUM)
		.value("KRUG_SMALL",      GameObjectType::KRUG_SMALL)

		.value("WOLF",            GameObjectType::WOLF)
		.value("WOLF_SMALL",      GameObjectType::WOLF_SMALL)

		.value("RAZORBEAK",       GameObjectType::RAZORBEAK)
		.value("RAZORBEAK_SMALL", GameObjectType::RAZORBEAK_SMALL)
		
		.value("GROMP",           GameObjectType::GROMP)
		.value("BLUE",            GameObjectType::BLUE)
		.value("RED",             GameObjectType::RED)
		.value("CRAB",            GameObjectType::CRAB)

		.value("PLANT_EXPLOSION", GameObjectType::PLANT_EXPLOSION)
		.value("PLANT_HEALING",   GameObjectType::PLANT_HEALING)
		.value("PLANT_VISION",    GameObjectType::PLANT_VISION)

		.value("SHACO_BOX",       GameObjectType::SHACO_BOX)
		.value("TEEMO_MUSHROOM",  GameObjectType::TEEMO_MUSHROOM)

		.value("SHACO_CLONE",     GameObjectType::SHACO_CLONE)
		.value("LEBLANC_CLONE",   GameObjectType::LEBLANC_CLONE)
		;
}
