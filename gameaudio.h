#ifndef GAMEAUDIO_H
#define GAMEAUDIO_H

#include <QAudioOutput>
#include <QMediaPlayer>
#include <QSoundEffect>

class GameAudio
{
private:
    std::unique_ptr<QMediaPlayer> bgMusicPlayer;
    std::unique_ptr<QAudioOutput> audioOutput;

    std::unique_ptr<QSoundEffect>
        dealSound,
        betSound,
        clickSound;

    static std::unique_ptr<QSoundEffect> loadSoundEffect(const QString&);

public:
    GameAudio();

    void playBetSound();
    void playClickSound();
    void playDealSound();

    QAudioOutput& getAudioOutput();
    QMediaPlayer& getBgMusicPlayer();
};

#endif // GAMEAUDIO_H
