#include "gameaudio.h"

GameAudio::GameAudio()
    : bgMusicPlayer(std::make_unique<QMediaPlayer>()),
    audioOutput(std::make_unique<QAudioOutput>()),
    dealSound(loadSoundEffect("deal.wav")),
    betSound(loadSoundEffect("bet.wav")),
    clickSound(loadSoundEffect("click.wav"))
{
    bgMusicPlayer->setAudioOutput(audioOutput.get());
    bgMusicPlayer->setSource(QUrl("qrc:/sound/soundtrack.ogg"));
    bgMusicPlayer->setLoops(QMediaPlayer::Infinite);
    audioOutput->setVolume(0.035f);
    bgMusicPlayer->play();
}

void GameAudio::enableSoundEffects(bool enable)
{
    soundEffectsEnabled = enable;
}

void GameAudio::playBetSound()
{
    playSound(*betSound);
}

void GameAudio::playClickSound()
{
    playSound(*clickSound);
}

void GameAudio::playDealSound()
{
    playSound(*dealSound);
}

std::unique_ptr<QSoundEffect> GameAudio::loadSoundEffect(const QString &file)
{
    auto sound = std::make_unique<QSoundEffect>();
    sound->setSource(QUrl("qrc:/sound/" + file));
    sound->setVolume(0.3f);
    return sound;
}

void GameAudio::playSound(QSoundEffect &sound)
{
    if (soundEffectsEnabled)
        sound.play();
}

QAudioOutput& GameAudio::getAudioOutput()
{
    return *audioOutput;
}

QMediaPlayer& GameAudio::getBgMusicPlayer()
{
    return *bgMusicPlayer;
}

