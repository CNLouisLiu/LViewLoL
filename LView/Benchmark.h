#pragma once

struct UIBenchmark {
	float renderTimeMs;
	float processTimeMs;
};

struct ReadBenchmark {
	float readChampsMs;
	float readRendererMs;
	float readMobsMs;
	float readTurretsMs;
};

struct ViewBenchmark {
	float drawSettingsMs;
	float drawPanelMs;
	float drawWorldOverlayMs;
	float drawMinimapOverlayMs;
};