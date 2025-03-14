<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Xfce](05-Xfce.html) | [Network](10-Network.html) | FFmpeg | [Systemd](20-Systemd.html) | [Bugs](25-Bugs.html) | [Other](99-Other.html) ]**

## FFmpeg

---

https://ffmpeg.org/documentation.html  
https://ffmpeg.org/ffmpeg-filters.html  

[https://www.codeproject.com/Tips/5356341/](https://www.codeproject.com/Tips/5356341/How-to-Compile-FFmpeg-6-0-in-Linux-and-What-New-Th)  


#### Audio/Video

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
    

#### Audio

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


#### Images
    
* Resize image
    
    ```
    ffmpeg -hide_banner -loglevel error -y \
    -i "input.jpg" -q:v 1 -vf scale=1680:1050:flags=lanczos "output.jpg"
    ```


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


