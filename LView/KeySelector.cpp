#include "KeySelector.h"
#include "imgui.h"

KeySelector::KeySelector(const char * comboName) {
	this->comboName = comboName;
	this->selectedKey = 0;
}

KeySelector::KeySelector(const char* comboName, HKey key) {
	this->comboName = comboName;
	this->selectedKey = key;
}

void DrawButton(HKey key, HKey& clickedBtn, bool& wasClicked) {
	if (ImGui::Button(HKeyNames[key])) {
		clickedBtn = key;
		wasClicked = true;
	}
	ImGui::SameLine();
}

void KeySelector::DrawImGuiWidget() {

	ImGui::PushID(this);
	ImGui::BeginGroup();
	if (ImGui::Button(HKeyNames[selectedKey])) {
		ImGui::OpenPopup("Keys");
	}
	ImGui::SameLine();
	ImGui::Text(comboName);
	ImGui::EndGroup();

	
	if (ImGui::BeginPopup("Keys")) {

		HKey clickedBtn = HKey::NO_KEY;
		bool wasClicked = false;

		ImGui::BeginGroup();
		DrawButton(HKey::ESC, clickedBtn, wasClicked);
		DrawButton(HKey::F1, clickedBtn, wasClicked);
		DrawButton(HKey::F2, clickedBtn, wasClicked);
		DrawButton(HKey::F3, clickedBtn, wasClicked);
		DrawButton(HKey::F4, clickedBtn, wasClicked);
		DrawButton(HKey::F6, clickedBtn, wasClicked);
		DrawButton(HKey::F6, clickedBtn, wasClicked);
		DrawButton(HKey::F7, clickedBtn, wasClicked);
		DrawButton(HKey::F8, clickedBtn, wasClicked);
		DrawButton(HKey::F9, clickedBtn, wasClicked);
		DrawButton(HKey::F10, clickedBtn, wasClicked);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		DrawButton(HKey::TILDE, clickedBtn, wasClicked);
		DrawButton(HKey::_1, clickedBtn, wasClicked);
		DrawButton(HKey::_2, clickedBtn, wasClicked);
		DrawButton(HKey::_3, clickedBtn, wasClicked);
		DrawButton(HKey::_4, clickedBtn, wasClicked);
		DrawButton(HKey::_5, clickedBtn, wasClicked);
		DrawButton(HKey::_6, clickedBtn, wasClicked);
		DrawButton(HKey::_7, clickedBtn, wasClicked);
		DrawButton(HKey::_8, clickedBtn, wasClicked);
		DrawButton(HKey::_9, clickedBtn, wasClicked);
		DrawButton(HKey::_0, clickedBtn, wasClicked);
		DrawButton(HKey::MINUS, clickedBtn, wasClicked);
		DrawButton(HKey::EQUAL , clickedBtn, wasClicked);
		DrawButton(HKey::BS, clickedBtn, wasClicked);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		DrawButton(HKey::Tab, clickedBtn, wasClicked);
		DrawButton(HKey::Q, clickedBtn, wasClicked);
		DrawButton(HKey::W, clickedBtn, wasClicked);
		DrawButton(HKey::E, clickedBtn, wasClicked);
		DrawButton(HKey::R, clickedBtn, wasClicked);
		DrawButton(HKey::T, clickedBtn, wasClicked);
		DrawButton(HKey::Y, clickedBtn, wasClicked);
		DrawButton(HKey::U, clickedBtn, wasClicked);
		DrawButton(HKey::I, clickedBtn, wasClicked);
		DrawButton(HKey::O, clickedBtn, wasClicked);
		DrawButton(HKey::P, clickedBtn, wasClicked);
		DrawButton(HKey::LBRACKET , clickedBtn, wasClicked);
		DrawButton(HKey::RBRACKET, clickedBtn, wasClicked);
		DrawButton(HKey::ENTER, clickedBtn, wasClicked);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		DrawButton(HKey::CAPS, clickedBtn, wasClicked);
		DrawButton(HKey::A, clickedBtn, wasClicked);
		DrawButton(HKey::S, clickedBtn, wasClicked);
		DrawButton(HKey::D, clickedBtn, wasClicked);
		DrawButton(HKey::F, clickedBtn, wasClicked);
		DrawButton(HKey::G, clickedBtn, wasClicked);
		DrawButton(HKey::H, clickedBtn, wasClicked);
		DrawButton(HKey::J, clickedBtn, wasClicked);
		DrawButton(HKey::K, clickedBtn, wasClicked);
		DrawButton(HKey::L, clickedBtn, wasClicked);
		DrawButton(HKey::SEMICOLON, clickedBtn, wasClicked);
		DrawButton(HKey::SINGLE_QUOTE, clickedBtn, wasClicked);
		DrawButton(HKey::BACKSLASH, clickedBtn, wasClicked);
		DrawButton(HKey::NO_KEY, clickedBtn, wasClicked);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		DrawButton(HKey::LSHIFT, clickedBtn, wasClicked);
		DrawButton(HKey::Z, clickedBtn, wasClicked);
		DrawButton(HKey::X, clickedBtn, wasClicked);
		DrawButton(HKey::C, clickedBtn, wasClicked);
		DrawButton(HKey::V, clickedBtn, wasClicked);
		DrawButton(HKey::B, clickedBtn, wasClicked);
		DrawButton(HKey::N, clickedBtn, wasClicked);
		DrawButton(HKey::M, clickedBtn, wasClicked);
		DrawButton(HKey::COMMA, clickedBtn, wasClicked);
		DrawButton(HKey::DOT, clickedBtn, wasClicked);
		DrawButton(HKey::FRONTSLASH, clickedBtn, wasClicked);
		DrawButton(HKey::RSHIFT, clickedBtn, wasClicked);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		DrawButton(HKey::CTRL, clickedBtn, wasClicked);
		DrawButton(HKey::ALT, clickedBtn, wasClicked);
		DrawButton(HKey::SPACE, clickedBtn, wasClicked);
		DrawButton(HKey::HOME, clickedBtn, wasClicked);
		DrawButton(HKey::INSERT, clickedBtn, wasClicked);
		DrawButton(HKey::END, clickedBtn, wasClicked);
		DrawButton(HKey::PAGE_DOWN, clickedBtn, wasClicked);
		DrawButton(HKey::PAGE_UP, clickedBtn, wasClicked);
		ImGui::EndGroup();

		if (wasClicked) {
			selectedKey = clickedBtn;
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::PopID();
}

HKey KeySelector::GetSelectedKey() {
	return (HKey)selectedKey;
}

void KeySelector::SelectKey(HKey key)
{	
	selectedKey = key;
}
