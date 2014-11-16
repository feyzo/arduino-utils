arduino-utils
=============

Useful code snippets to help my arduino development

Serial port to pin signal communication
------
Code:
[serial-to-pin-communication.ino](https://github.com/feyzo/arduino-utils/blob/master/serial-to-pin-communication.ino)

Usage:
- `<01-123>` sends 123 to pin #1
- `<09-999>` sends 999 to pin #9
- `<06-003>` sends 3   to pin #6
- `<08-048>` sends 48  to pin #8
- `<11-421>` sends 48  to pin #8

Warnings:
- Doesn't support numbers over integer limit, 32767
- Doesn't support negative values but you can set your own "zero". For example you can treat numbers below 100 as negative.
