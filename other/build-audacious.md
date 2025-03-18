<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Build](10-build.html) ]**

## Audacious

---

* plugins

    https://github.com/audacious-media-player/audacious-plugins/blob/master/meson_options.txt  

    ```
    sudo apt install \
    audacious-dev libarchive-dev libasound2-dev libavcodec-dev \
    libavformat-dev libavutil-dev libbinio-dev libbs2b-dev libcairo2-dev \
    libcddb2-dev libcue-dev libcurl4-gnutls-dev libfaad-dev libflac-dev \
    libfluidsynth-dev libjson-glib-dev liblirc-dev libmms-dev libmodplug-dev \
    libmp3lame-dev libmpg123-dev libneon27-gnutls-dev libnotify-dev \
    libogg-dev libopenmpt-dev libopus-dev libopusfile-dev libpipewire-0.3-dev \
    libpulse-dev libsamplerate0-dev libsdl2-dev libsidplayfp-dev \
    libsndfile1-dev libsndio-dev libsoxr-dev libtag-c-dev libvorbis-dev \
    libwavpack-dev libxcomposite-dev libxml2-dev
    ```

    ```
    git clone https://github.com/audacious-media-player/audacious-plugins.git
    cd audacious-plugins
    meson setup build -Dbuildtype=release -Dqt=false
    ```

    ```
    audacious-plugins 4.5-devel

      Directories
        Prefix                               : /usr/local
        Bin dir                              : bin
        Lib dir                              : lib/aarch64-linux-gnu
        Data dir                             : share

      GUI Toolkits
        Qt 5 support                         : false
        Qt 6 support                         : false
        GTK 2 support                        : false
        GTK 3 support                        : true

      Audio Formats
        Audio CD                             : false
        Free Lossless Audio Codec            : true
        Ogg Vorbis                           : true
        Opus                                 : true
        MIDI (via FluidSynth)                : true
        MPEG-1 Layer I/II/III (via mpg123)   : true
        MPEG-2/4 AAC                         : true
        WavPack                              : true

      External Decoders
        FFmpeg                               : true
        Libsndfile                           : true

      Chiptunes
        AdLib synthesizer (adplug)           : false
        Commodore 64 audio (sid)             : true
        Game Music Emu (spc, nsf, gbs, etc.) : true
        ModPlug                              : true
        OpenMPT                              : true
        Nintendo DS audio (xsf)              : true
        PlayStation audio (psf/psf2)         : true
        Vortex Tracker (vtx)                 : true

      Other Inputs
        Metronome                            : true
        Tone Generator                       : true

      Effects
        Background Music                     : true
        Bauer stereophonic-to-binaural (bs2b): true
        Bitcrusher                           : true
        Channel Mixer                        : true
        Crystalizer                          : true
        Dynamic Range Compressor             : true
        Echo/Surround                        : true
        Extra Stereo                         : true
        LADSPA Host (requires GTK)           : true
        Sample Rate Converter                : true
        Silence Removal                      : true
        SoX Resampler                        : true
        Speed and Pitch                      : true
        Voice Removal                        : true

      Outputs
        Advanced Linux Sound Architecture    : true
        Jack Audio Connection Kit            : true
        Open Sound System                    : true
        PipeWire                             : true
        PulseAudio                           : true
        Simple DirectMedia Layer             : true
        Sndio                                : true
        Win32 waveOut                        : false
        FileWriter                           : true
          -> MP3 encoding                    : true
          -> Vorbis encoding                 : true
          -> FLAC encoding                   : true

      Playlists
        Cue sheets                           : true
        M3U playlists                        : true
        Microsoft ASX (legacy)               : true
        Microsoft ASX 3.0                    : true
        PLS playlists                        : true
        XML Sharable Playlist Format (XSPF)  : true

      Transports
        FTP, SFTP, SMB (via GIO)             : true
        HTTP/HTTPS (via neon)                : true
        MMS (via libmms)                     : true

      General
        Ampache browser (requires Qt)        : false
        Delete Files                         : true
        Libnotify OSD                        : true
        Linux Infrared Remote Control (LIRC) : true
        Lyrics Viewer                        : true
        MPRIS 2 Server                       : true
        Scrobbler 2.0                        : true
        Song Change                          : true

      GTK Support
        GTK Interface                        : true
        Winamp Classic Interface             : true
        Album Art                            : true
        Blur Scope                           : true
        OpenGL Spectrum Analyzer             : true
        Playlist Manager                     : true
        Search Tool                          : true
        Spectrum Analyzer (2D)               : true
        Status Icon                          : true
        VU Meter                             : true
        X11 Global Hotkeys                   : true
        X11 On-Screen Display (aosd)         : true

      User defined options
        buildtype                            : release
        qt                                   : false
    ```
    ```
    meson compile -C build
    sudo meson install -C build
    ```

* audacious

    https://github.com/audacious-media-player/audacious  

    ```
    git clone https://github.com/audacious-media-player/audacious.git
    cd audacious
    meson setup build -Dbuildtype=release -Dqt=false
    meson compile -C build
    sudo meson install -C build
    ```
<br/>

