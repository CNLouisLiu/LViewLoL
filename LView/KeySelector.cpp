#include "KeySelector.h"
#include "imgui.h"

const char* KeySelector::keyNames[3] = { "None", "Space", "Tilde" };
const HKey KeySelector::keyValues[3] = { HKey::NO_KEY, HKey::SPACE, HKey::TILDE };
std::map<HKey, int> KeySelector::keyToIndex = {
	{HKey::NO_KEY, 0},
	{HKey::SPACE, 1},
	{HKey::TILDE, 2}
};

KeySelector::KeySelector(const char* comboName, HKey key) {
	this->comboName = comboName;

	auto it = keyToIndex.find(key);
	if (it == keyToIndex.end())
		throw std::runtime_error("Unsupported key provided to KeySelector");
	this->selectedKey = it->second;
}

void KeySelector::Draw() {
	if (ImGui::BeginCombo(comboName, keyNames[selectedKey])) {
		for (int i = 0; i < numKeys; ++i) {
			if (ImGui::Selectable(keyNames[i])) {
				selectedKey = i;
			}
		}
		ImGui::EndCombo();
	}
}

HKey KeySelector::GetKey() {
	return keyValues[selectedKey];
}