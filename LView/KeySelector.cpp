#include "KeySelector.h"
#include "imgui.h"

const char* KeySelector::keyNames[18] = { 
	"None", "Space", "Tilde", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8",
	"Z", "X", "C", "V", "B", "N", "M"
};
const HKey KeySelector::keyValues[18] = { 
	HKey::NO_KEY, HKey::SPACE, HKey::TILDE,
	HKey::F1, HKey::F2, HKey::F3, HKey::F4, HKey::F5, HKey::F6, HKey::F7, HKey::F8,
	HKey::Z, HKey::X, HKey::C, HKey::V, HKey::B, HKey::N, HKey::M,
};

std::map<HKey, int> KeySelector::keyToIndex = {
	{HKey::NO_KEY, 0},
	{HKey::SPACE, 1},
	{HKey::TILDE, 2},

	{HKey::F1, 3},
	{HKey::F2, 4},
	{HKey::F3, 5},
	{HKey::F4, 6},
	{HKey::F5, 7},
	{HKey::F6, 8},
	{HKey::F7, 9},
	{HKey::F8, 10},

	{HKey::Z, 11},
	{HKey::X, 12},
	{HKey::C, 13},
	{HKey::V, 14},
	{HKey::B, 15},
	{HKey::N, 16},
	{HKey::M, 17},
};

KeySelector::KeySelector(const char * comboName) {
	this->comboName = comboName;
	this->selectedKey = 0;
}

KeySelector::KeySelector(const char* comboName, HKey key) {
	this->comboName = comboName;

	auto it = keyToIndex.find(key);
	if (it == keyToIndex.end())
		throw std::runtime_error("Unsupported key provided to KeySelector");
	this->selectedKey = it->second;
}

void KeySelector::DrawImGuiWidget() {
	if (ImGui::BeginCombo(comboName, keyNames[selectedKey])) {
		for (int i = 0; i < numKeys; ++i) {
			if (ImGui::Selectable(keyNames[i])) {
				selectedKey = i;
			}
		}
		ImGui::EndCombo();
	}
}

HKey KeySelector::GetSelectedKey() {
	return keyValues[selectedKey];
}

void KeySelector::SelectKey(HKey key)
{	
	selectedKey = keyToIndex[key];
}
