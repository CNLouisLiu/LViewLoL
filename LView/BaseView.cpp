#include "BaseView.h"

void BaseView::OnLoadSettings(ConfigSet& configs) {
	enabled = configs.Get<bool>("enabled", false);
}

void BaseView::OnSaveSettings(ConfigSet& configs) {
	configs.Set<bool>("enabled", enabled);
}

void BaseView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {};
void BaseView::DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {};

void BaseView::DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {};
void BaseView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {};
