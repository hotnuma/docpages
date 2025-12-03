<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Linux](00-linux.html) | [Xfce](05-xfce.html) | AVideo | [Network](11-network.html) | [Systemd](20-systemd.html) | [Bugs](25-bugs.html) | [Other](99-other.html) ]**

## AVideo

---

https://ffmpeg.org/documentation.html  
https://ffmpeg.org/ffmpeg-filters.html  
https://github.com/BtbN/FFmpeg-Builds/releases  

[https://www.codeproject.com/Tips/5356341/](https://www.codeproject.com/Tips/5356341/How-to-Compile-FFmpeg-6-0-in-Linux-and-What-New-Th)  


#### FFmpeg A/V

* Change aspect ratio

    `ffmpeg -y -i "input.mp4" -aspect "4:3" -c copy "output.mp4"`

* Get a 1 min sample from 2 min of the beginning

    ffmpeg -y -ss 00:02:00 -i "input.mp4" -t 00:01:00 -c copy "output.mp4"

* Get a 1 min sample with audio only

    ffmpeg -y -ss 00:02:00  -i "input.mp4" -t 00:01:00 -map 0:1 -c copy "output.mp4"

* Get a 1 min samle with video only

    ffmpeg -y -ss 00:02:00 -i "input.mp4" -t 00:01:00 -map 0:0 -c copy "output.mp4"

* Get file informations

    `ffprobe -hide_banner "input.mp4"`

    `ffprobe -v quiet -show_format -show_streams "input.mp4"`
    

#### FFmpeg Audio

* Mp3 encoding

    `ffmpeg -y -i "input.m4a" -c:a libmp3lame -b:a 192k "output.mp3"`
    
* Keep left channel

    `ffmpeg -y -i "input.mp4" -c:v copy -c:a libmp3lame -b:a 192k -af "pan=stereo|c0=c0|c1=c0" "output.mp4"`
    
* Keep right channel

    `ffmpeg -y -i "input.mp4" -c:v copy -c:a libmp3lame -b:a 192k -af "pan=stereo|c0=c1|c1=c1" "output.mp4"`
    
* Audio normalize

    http://superuser.com/questions/323119/  

    Analyze audio level with volumedetect
    
    `ffmpeg -y -i "input.mp4" -af "volumedetect" -f null /dev/null`
    
    Read "max_volume", for example -22.5 dB, then amplify audio channel by +22.5dB.
    
    `ffmpeg -y -i "input.mp4" -c:v copy -c:a libmp3lame -b:a 192k -af "volume=22.5dB" "output.mp4"`
    
* Advance or delay audio by one second

    `ffmpeg -y -i "input.mp4" -itsoffset -1.0 -i "input.mp4" -map 0:0 -map 1:1 -c copy "output.mp4"`

    `ffmpeg -y -i "input.mp4" -itsoffset +1.0 -i "input.mp4" -map 0:0 -map 1:1 -c copy "output.mp4"`
    
* Choose default audio channel

    ```
    ffmpeg -y -i "input.mp4" -map 0:0 -map 0:2 -map 0:1 \
    -disposition:a:0 default -disposition:a:1 none -c copy "output.mp4"
    ```
    
* Change audio speed

    `ffmpeg -y -i "audio.mp3" -af "atempo=1.001" -b:a 192k "audio-faster.mp3"`

* Audio filter

    `ffmpeg -y -i "input.mp4" -c:v copy -af "highpass=f=100" "output.mp4"`


#### FFmpeg Images
    
* Resize image
    
    ```
    ffmpeg -hide_banner -loglevel error -y \
    -i "input.jpg" -q:v 1 -vf scale=1680:1050:flags=lanczos "output.jpg"
    ```


#### mpv
    
    https://www.reddit.com/r/linuxquestions/comments/clyt9z/  
    
    In mpv.conf : `ytdl-format=bestvideo[height<=?480]+bestaudio/best`


#### Subtitles

* Convert sub to srt online

    https://subtitletools.com/convert-sub-idx-to-srt-online  

* Extract subs with MKVToolNix

    `mkvextract tracks "input.mkv" 2:out.idx`

* Remove subtitles and chapters

    `ffmpeg -y -i "input.mp4" -c copy -sn "output.mp4"`

    `ffmpeg -y -i "input.mp4" -c copy -map_chapters -1 "output.mp4"`
    
    `ffmpeg -y -i "input.mp4" -c copy -dn -map_metadata:c -1 "output.mp4"`
    

#### yt-dlp

* Download subtitles from YouTube

    ```
    yt-dlp --list-subs "URL"
    yt-dlp --write-sub --sub-lang en --skip-download "URL"
    yt-dlp --write-sub --convert-subs=srt --skip-download "URL"
    yt-dlp --write-auto-sub --sub-lang fr --skip-download "URL"
    ```
    
* Download thumbnail
    
    `yt-dlp --write-thumbnail --skip-download "URL"`

* Use cookies

    `yt-dlp --cookies=cookies/youtube.txt "URL"`


#### Other

* Concatenating files
    
    https://stackoverflow.com/questions/7333232/  
    https://trac.ffmpeg.org/wiki/Concatenate  

    Create a file containing the list of files to concatenate :
    
    ```
    file 'part1.mp4'
    file 'part2.mp4'
    file 'part3.mp4'
    ``` 

    Then execute the concat command :

    `ffmpeg -f concat -safe 0 -i "input.txt" -c copy "output.mp4"`

* Write title metadata
    
    `ffmpeg -y -i "input.mp4" -c copy -metadata title="Test title" "output.mp4"`

<br/>

<!--
#### ffmpeg

* Pts has no value error

    First, a background on why this error exists.
    AVI does not support variable frame rate video.
    So somewhere at the start of the file the frame rate is recorded.
    mp4 does support variable frame rate, so it is required that
    the duration of each frame is known. In ffmpeg the pts generation
    for fixed frame rate video is usually handled by the decoder.
    but by using -codec copy, you are bypassing the decoder.
    The solution is specifying -fflags +genpts (must be before
    the input file is specified with -i).

    Generate pts
    
    `ffmpeg -fflags +genpts -i film.avi -codec copy film.mp4`
    
    or
    
    ```
    ffmpeg -i source.mp4 -map 0:v -vcodec copy -bsf:v h264_mp4toannexb source-video.h264

    ffmpeg -fflags +genpts -r 60 -i source-video.h264 -vcodec copy output.mp4
    ```

#### Images

    On peut modifier les options de VLC pour qu'il utilise une numérotation séquencielle.
    Dans Options/Préférences, Video, cocher la case "Numérotation séquentielle".

* 2x2 images, chacune de 333px de large :

    ffmpeg -i "vlcsnap-%05d.png" -vf "scale=333:-1,tile=2x2" "output.png"

* 3x3 images, chacune de 111px de large :

    ffmpeg -i "vlcsnap-%05d.png" -vf "scale=111:-1,tile=3x3" "output.png"

    "%05d" signifie, un nombre de 5 chiffres, par exemple vlcsnap-00001.png.

    A noter que les images doivent être consécutives,
    exemple pic-001.png, pic-002.png, pic-003.png etc...

* Créer automatiquement à partir d'une série de captures d'écran :

    ffmpeg -i "input.avi" -frames 1 -vf "select=not(mod(n\,7600)),scale=111:-1,tile=4x4" "output.png"


#### Other

* Créer une capture d'écran toutes les 5 minutes :

    ffmpeg -i "input.avi" -vf fps=1/300 "pic-%03d.png"

    (300 = 5 x 60 secondes)

* Appliquer le même traitement sur une série d'images :

    ffmpeg -y -i "input-%03d.png" -vf "scale=666:-1" "output-%03d.png"

* Concatenating files

    concat VOB files      
    copy /b *.vob output.vob
    cat file*.vob > Allfiles.vob

* Enregistrer un flux en direct

    ffmpeg -i http://live.francetv.fr/simulcast/France_3/hls_v1/index.m3u8 \
    -bsf:a aac_adtstoasc -c:a copy -c:v copy output.mp4

* Utiliser un preset

    ffmpeg -i "input.mp4" -preset ultrafast -crf 18 "output.mp4"
    ffmpeg -i "input.mp4" -preset slow -crf 18 "output.mp4"

    Le preset détermine la compression et par conséquent la qualité et la taille du fichier.
    La valeur par défaut est "médium". Les valeurs plus rapides sont fast, faster, veryfast,
    superfast, ultrafast. Les valeurs plus lents sont, slow, slower, veryslow, placebo.

* Upscale and unsharp with default values :

    ffmpeg -i input.mp4 -vf "scale=640:480:flags=lanczos,unsharp" output.mp4
    ffmpeg -i input.mp4 -vf "scale=640:480,unsharp" -sws_flags lanczos output.mp4

    For downscaling use Lanczosresize only
    For upscaling use Bicubicresize with 0.45 to 0.6 sharpening.    

* Diaporama

    ffmpeg -framerate 1/12 -i pic-%03d.png -c:v libx264 -r 25 -pix_fmt yuv420p out.mp4
    ffmpeg -i "vlcsnap-%05d.png" -vf "scale=-1:480,pad=640:480:154:0" "input-%05d.png"

* Add metadata

    ffmpeg -i "input.avi" -c copy -metadata title="Le schpountz" "output.avi"
    ffmpeg -i "input.avi" -c copy -map_metadata -1 -metadata title="1938 - Le schpountz" -metadata comment="tt0030722" "output.avi"

* Curves
    
    https://hhsprings.bitbucket.io/docs/programming/examples/ffmpeg/manipulating_video_colors/curves.html
    
    ```
    curves=preset=darker
    curves=preset=lighter
    ```

* Other

    ffmpeg -ss 00:00:14 -i "D:/Films/Convert/1945 - Carmen-orig.mp4" \
    -deinterlace -b:v 1200k -vf hue=s=0,crop=704:566:0:2 "1945 - Carmen-orig.mp4"

    ffmpeg -i "D:/Films/Films 4-7/1935 - La Kermesse héroïque.avi" \
    -b:v 1000k -vf scale=720:576 "1935 - La Kermesse héroïque.avi"

    ffmpeg -t 01:51:20 -i "D:/Films Supprimer/1945 - La vie de boheme.ts" \
    -b:v 1000k -deinterlace -vf crop=530:566:91:2 -aspect 4:3

    ffmpeg -i "D:/Films/Convert/1929 - Adieu Mascotte.mp4" -preset ultrafast \
    -crf 22 -deinterlace -r 25 -vf crop=626:470:8:6 "1929 - Adieu Mascotte.mp4"

    ffmpeg -y -i "1934 - Caravane-orig.mp4" -preset slow -vsync 0 -crf 22 \
    -vf hue=s=0,crop=938:704:15:3,unsharp=3:3:0.4 -af highpass=f=100 "1934 - Caravane.mp4"

    ffmpeg -y -t 01:34:46 -i "D:/Films Selection/_1935 - L'École des cocottes.avi" -crf 18 \
    -preset slow -vsync 0 -vf hue=s=0,crop=680:544:14:14,unsharp=3:3:0.3 -b:a 256k \
    "1935 - L'École des cocottes-unsharp303.mp4"

    ffmpeg -y -t 01:29:54 -i "D:/Films Convert/1941 - Valet Maitre.mkv" -b:v 2000k \
    -preset slow -vsync 0 -vf hue=s=0,crop=710:568:0:0,unsharp=3:3:0.3 "1941 - Valet Maitre.mp4"

    "Too many packets buffered for output stream"

    -max_muxing_queue_size 1024

    ffmpeg -framerate 1/2 -loop 1 -t 1 -i NWL1.png -framerate 60 -loop 1 -t 1 -i NWL2.png -framerate 60 -loop 1 -t 1 -i NWL3.png -framerate 60 -loop 1 -t 1 -i NWL4.png -framerate 60 -loop 1 -t 1 -i NWL5.png -filter_complex "[1:v][0:v]blend=all_expr='A*(if(gte(T,0.5),1,T/0.5))+B*(1-(if(gte(T,0.5),1,T/0.5)))'[b1v]; [2:v][1:v]blend=all_expr='A*(if(gte(T,0.5),1,T/0.5))+B*(1-(if(gte(T,0.5),1,T/0.5)))'[b2v]; [3:v][2:v]blend=all_expr='A*(if(gte(T,0.5),1,T/0.5))+B*(1-(if(gte(T,0.5),1,T/0.5)))'[b3v]; [4:v][3:v]blend=all_expr='A*(if(gte(T,0.5),1,T/0.5))+B*(1-(if(gte(T,0.5),1,T/0.5)))'[b4v]; [0:v][b1v][1:v][b2v][2:v][b3v][3:v][b4v][4:v]concat=n=9:v=1:a=0,format=yuv420p,scale=480:270[vx]" -map "[vx]" -c:v libx264 -r 30 -pix_fmt yuv420p "EXfondu2.mp4"

    ffmpeg -i "video.mp4"  -i "audio.mp3" -c copy -shortest "output.mp4"

    youtube-dl --extract-audio --audio-format mp3 -l "https://www.youtube.com/watch?v=xN8Q75ov6A4"

* remux avi to mp4

    avi2raw.exe -v "D:\Films\Films 3-8\1936 - Topaze.avi" "1936 - Topaze.264"
    avi2raw.exe -a "D:\Films\Films 3-8\1936 - Topaze.avi" "1936 - Topaze.aac"
    ffmpeg -i "D:\Films\Films 3-8\1936 - Topaze.avi" -vn -c:a copy "1936 - Topaze.aac"
    mp4box.exe -add "1936 - Topaze.264" -fps 25 -add "1936 - Topaze.aac" "1936 - Topaze.mp4"
    ffmpeg -i input.mkv -itsoffset 1.0 -i input.mkv -map 0:0 -map 1:1 -c copy output.mkv   
    ffmpeg -ss 00:00:33.5 -i "D:\Downloads\Invitation.to.the.Waltz.1935.mkv" \
    -c copy -avoid_negative_ts 1 "D:\Downloads\1935 - Invitation to the Waltz.mkv"

* screenshot

    ffmpeg -ss 00:00:30 -i "D:\Films\Convert\1937 - Forfaiture-0.mkv" -vframes 1 -q:v 2 output.jpg

-->


