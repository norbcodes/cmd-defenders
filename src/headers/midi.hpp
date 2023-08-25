#pragma once

#include <string>

void InitializeSynth();
void DeleteSynth();
void LoadSoundfont(const std::string& path);
void LoadMidi(const std::string& path);
void StartPlayback();
void TogglePause();
void StopPlayback();