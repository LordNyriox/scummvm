/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef MADE_MADE_H
#define MADE_MADE_H

#include "made/sound.h"
#include "made/detection.h"

#include "engines/engine.h"

#include "common/random.h"

/**
 * This is the namespace of the Made engine.
 *
 * Status of this engine: ???
 *
 * Games using this engine:
 * - Return to Zork
 * - Leather Goddesses of Phobos 2
 * - The Manhole
 * - Rodney's Funscreen
 */
namespace Made {

const uint32 kTimerResolution = 40;

class ResourceReader;
class PmvPlayer;
class Screen;
class ScriptInterpreter;
class GameDatabase;
class MusicPlayer;
class MadeConsole;

class MadeEngine : public ::Engine {
protected:

	// Engine APIs
	Common::Error run() override;

public:
	MadeEngine(OSystem *syst, const MadeGameDescription *gameDesc);
	~MadeEngine() override;

	bool hasFeature(EngineFeature f) const override;
	void syncSoundSettings() override;

	Common::RandomSource *_rnd;
	const MadeGameDescription *_gameDescription;
	uint32 getGameID() const;
	uint32 getFeatures() const;
	uint16 getVersion() const;
	Common::Platform getPlatform() const;

public:
	PmvPlayer *_pmvPlayer;
	ResourceReader *_res;
	Screen *_screen;
	GameDatabase *_dat;
	ScriptInterpreter *_script;
	MusicPlayer *_music;

	uint16 _eventNum;
	int _eventMouseX, _eventMouseY;
	uint16 _eventKey;

	int _soundRate;
	bool _autoStopSound;
	uint _soundEnergyIndex;
	SoundEnergyArray *_soundEnergyArray;

	uint32 _musicBeatStart;
	uint32 _cdTimeStart;
	bool _introMusicDigital;

	int32 _timers[50];
	int16 getTicks();
	int16 getTimer(int16 timerNum);
	void setTimer(int16 timerNum, int16 value);
	void resetTimer(int16 timerNum);
	int16 allocTimer();
	void freeTimer(int16 timerNum);
	void resetAllTimers();

	const Common::String getTargetName() { return _targetName; }
	Common::String getSavegameFilename(int16 saveNum);

	void handleEvents();

protected:
	void pauseEngineIntern(bool pause);
};

} // End of namespace Made

#endif /* MADE_H */
