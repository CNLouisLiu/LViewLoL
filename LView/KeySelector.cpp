#include "KeySelector.h"
#include "imgui.h"

const char* KeySelector::keyNames[11] = { 
	"None", "Space", "Tilde", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"
};
const HKey KeySelector::keyValues[11] = { 
	HKey::NO_KEY, HKey::SPACE, HKey::TILDE,
	HKey::F1, HKey::F2, HKey::F3, HKey::F4, HKey::F5, HKey::F6, HKey::F7, HKey::F8,
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
};

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