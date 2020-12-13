#include "TFCardPickerView.h"

TFCardPickerView::TFCardPickerView()
	:keyYellowCard("Key for yellow card"),
	keyRedCard("Key for red card"),
	keyBlueCard("Key for blue card")
{
}

const char * TFCardPickerView::GetName()
{
	return "Twisted Fate Card Picker";
}

void TFCardPickerView::OnSaveSettings(ConfigSet & configs) {
	configs.Set<int>("keyYellowCard", keyYellowCard.GetSelectedKey());
	configs.Set<int>("keyBlueCard", keyBlueCard.GetSelectedKey());
	configs.Set<int>("keyRedCard", keyRedCard.GetSelectedKey());
}

void TFCardPickerView::OnLoadSettings(ConfigSet & configs) {
	keyYellowCard.SelectKey((HKey)configs.Get<int>("keyYellowCard", HKey::Z));
	keyBlueCard.SelectKey((HKey)configs.Get<int>("keyBlueCard", HKey::NO_KEY));
	keyRedCard.SelectKey((HKey)configs.Get<int>("keyRedCard", HKey::NO_KEY));
}

void TFCardPickerView::DrawWorldSpaceOverlay(const MemSnapshot & snapshot, const MiscToolbox & toolbox)
{
	if (lookingForYellow && snapshot.localChampion->W.name == yellowCardName) {
		lookingForYellow = false;
		Input::PressKey(HKey::W);
		return;
	}
	else if (lookingForBlue && snapshot.localChampion->W.name == blueCardName) {
		lookingForBlue = false;
		Input::PressKey(HKey::W);
		return;
	}
	else if (lookingForRed && snapshot.localChampion->W.name == redCardName) {
		lookingForRed = false;
		Input::PressKey(HKey::W);
		return;
	}

	if (Input::WasKeyPressed(keyYellowCard.GetSelectedKey())) {
		lookingForYellow = true;
		lookingForBlue, lookingForRed = false, false;
		Input::PressKey(HKey::W);
	} else if (Input::WasKeyPressed(keyBlueCard.GetSelectedKey())) {
		lookingForBlue = true;
		lookingForYellow, lookingForRed = false, false;
		Input::PressKey(HKey::W);
	} else if (Input::WasKeyPressed(keyRedCard.GetSelectedKey())) {
		lookingForRed = true;
		lookingForYellow, lookingForBlue = false, false;
		Input::PressKey(HKey::W);
	}
}

void TFCardPickerView::DrawSettings(const MemSnapshot & snapshot, const MiscToolbox & toolbox)
{
	keyYellowCard.DrawImGuiWidget();
	keyBlueCard.DrawImGuiWidget();
	keyRedCard.DrawImGuiWidget();
}
