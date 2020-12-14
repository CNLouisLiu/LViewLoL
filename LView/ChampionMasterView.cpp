#include "ChampionMasterView.h"
#include "imgui.h"
#include "Utils.h"

ChampionMasterView::ChampionMasterView(std::map<std::string, std::list<BaseView*>> championViews)
{
	this->championViews = championViews;
}

const char * ChampionMasterView::GetName()
{
	return "Champion Specific";
}

void ChampionMasterView::OnSaveSettings(ConfigSet & configs) {
	for (auto it = championViews.begin(); it != championViews.end(); ++it) {
		std::string oldPrefix = configs.GetPrefixKey();
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			configs.SetPrefixKey(oldPrefix + "." + (*it2)->GetName());
			(*it2)->OnSaveSettings(configs);
			configs.SetPrefixKey(oldPrefix);
		}
	}
}

void ChampionMasterView::OnLoadSettings(ConfigSet & configs) {
	for (auto it = championViews.begin(); it != championViews.end(); ++it) {
		std::string oldPrefix = configs.GetPrefixKey();
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			configs.SetPrefixKey(oldPrefix + "." + (*it2)->GetName());
			(*it2)->OnLoadSettings(configs);
			configs.SetPrefixKey(oldPrefix);
		}
	}
}

void ChampionMasterView::DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	for (auto it = currentViews.begin(); it != currentViews.end(); ++it) {
		(*it)->DrawPanel(snapshot, toolbox);
	}
}

void ChampionMasterView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	for (auto it = currentViews.begin(); it != currentViews.end(); ++it) {
		(*it)->DrawWorldSpaceOverlay(snapshot, toolbox);
	}
}

void ChampionMasterView::DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	for (auto it = currentViews.begin(); it != currentViews.end(); ++it) {
		(*it)->DrawMinimapOverlay(snapshot, toolbox);
	}
}

void ChampionMasterView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	if (!firstFrameElapsed) {
		auto listIt = championViews.find(snapshot.localChampion->name);
		if (!firstFrameElapsed && listIt == championViews.end()) {
			ImGui::TextColored(Colors::Orange, "Sorry no scripts available for %s :(", snapshot.localChampion->name.c_str());
 			this->enabled = false;
			return;
		}
		firstFrameElapsed = true;
		currentViews = listIt->second;
	}

	for (auto it = currentViews.begin(); it != currentViews.end(); ++it) {
		BaseView* view = *it;
		if (ImGui::TreeNode(view->GetName())) {
			view->DrawSettings(snapshot, toolbox);
			ImGui::TreePop();
		}
	}
}
	