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
	float readMissilesMs;
};

struct ViewBenchmark {
	float drawSettingsMs;
	float drawPanelMs;
	float drawWorldOverlayMs;
	float drawMinimapOverlayMs;
};