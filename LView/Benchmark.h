#pragma once

struct UIBenchmark {
	float renderTimeMs;
	float processTimeMs;
};

struct ReadBenchmark {
	float readObjectsMs;
	float readRendererMs;
};

struct ViewBenchmark {
	float drawSettingsMs;
	float drawPanelMs;
	float drawOverlayMs;
};