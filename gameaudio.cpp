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

void GameAudio::playBetSound()
{
    betSound->play();
}

void GameAudio::playClickSound()
{
    clickSound->play();
}

void GameAudio::playDealSound()
{
     dealSound->play();
}

std::unique_ptr<QSoundEffect> GameAudio::loadSoundEffect(const QString &file)
{
    auto sound = std::make_unique<QSoundEffect>();
    sound->setSource(QUrl("qrc:/sound/" + file));
    sound->setVolume(0.3f);
    return sound;
}

QAudioOutput& GameAudio::getAudioOutput()
{
    return *audioOutput;
}

QMediaPlayer& GameAudio::getBgMusicPlayer()
{
    return *bgMusicPlayer;
}

