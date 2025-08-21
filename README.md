# 🛠️ Search & Rescue Aid Robot

**A robust, low-cost, remote-controlled robot designed to aid first responders in post-disaster environments by scouting hazardous zones, identifying survivors, and streaming live footage—all while remaining compact and modular.**

---

## 📦 Contents

- `CAD/` – Final 3D CAD models (Fusion 360)
- `STL/` – Exported 3D printable files
- `Drawings/` – Engineering drawings for fabrication
- `Code/` – ESP32-based Arduino code (motor control, IR LED, dual-camera switching, Bluetooth control via Dabble)
- `Media/` – Rendered images and beauty shots of the final design

---

## 🎯 Project Overview

Disasters like earthquakes and building collapses often trap survivors in unreachable spaces. This robot was designed to:

- **Navigate rubble** using dual-track movement and a low-profile body
- **Stream live video** via FPV cameras (day + IR night vision)
- **Be remotely controlled** using Bluetooth and the Dabble Gamepad interface
- **Be fabricated affordably** using common tools, 3D printed parts, and repurposed components (e.g. Ryobi tool batteries)

> 💡 Designed with scalability and accessibility in mind for use in developing regions or student labs.

---

## 🧠 Core Features

| Feature | Description |
|--------|-------------|
| **Mobility** | Tank-style treads with adjustable belt tension system |
| **Dual Camera System** | Day + IR night vision with software-based switching |
| **Controller** | ESP32 microcontroller + Bluetooth + Dabble mobile interface |
| **Frame** | Acrylic chassis with 3D-printed and laser-cut elements |
| **Power** | Standard 18V Ryobi power tool battery integration |
| **Lighting** | Array of infrared and visible LEDs for enhanced visibility |

---

## 🧬 Technical Specifications

- **Microcontroller**: ESP32
- **Motor Driver**: BTS7960
- **Motors**: 12V DC gear motors (approx. 10,200 RPM)
- **Camera**: Foxeer FPV with IR switching circuit
- **Battery**: Ryobi 18V tool battery
- **Control Interface**: Dabble Gamepad via Bluetooth
- **Track System**: Dual chain + GT2 belt drive
- **Body Material**: 4.5mm Acrylic (lasercut and bent)
- **All other parts**: PETG (ABS is better, but PLA also works) 3D printed components

---

## 🧪 Code Overview

Main controller logic includes:
- Speed ramping on joystick input
- Differential drive for turns
- Camera switching via button
- IR lighting and LED toggle

```cpp
if (GamePad.isUpPressed()) {
  motors.forwardA(); motors.forwardB();
  speedness += speedAmount;
}
...
if (GamePad.isTrianglePressed()) {
  digitalWrite(cam, HIGH);  // Toggle camera
}
```

> 📂 See [`/Code/main.ino`](./Code/main.ino) for full source.

---

## 🖨️ Manufacturing Instructions

- Print STL files using PLA+ with 100% infill for structural components.
- Laser cut acrylic sheets using templates provided in `/Drawings/`.
- Bend chassis with acrylic bender based on Fusion 360 flat patterns.
- Assemble with M3–M5 bolts and collars per engineering drawings.

---

## 🧪 Testing Notes

- All individual systems (motors, cameras, Bluetooth) confirmed functional
- Movement subsystem had traction issues due to belt tensioning—future revisions planned

---

## 📸 Gallery

### Final Design

![Render](https://github.com/abhi-243/SAR-Rover/blob/main/Media/photo1.jpg)
![Render](https://github.com/abhi-243/SAR-Rover/blob/main/Media/photo2.jpg)
![Render](https://github.com/abhi-243/SAR-Rover/blob/main/Media/render1.jpg)
![Render](https://github.com/abhi-243/SAR-Rover/blob/main/Media/render2.jpg)

----

### Animation

[![Watch the demo](docs/preview.png)](https://youtu.be/A4exE1CUXJw)

---

## 📚 Inspiration

Inspired by:
- [rctestflight snowcat robot](https://www.youtube.com/@rctestflight)
- Search-and-rescue robotics in earthquake zones
- Open-source robotics communities and Thingiverse designs

---

## 🤝 Acknowledgements

- **Mentors**: Mr. Jin Son (Design Theory), Mr. Rowan Simpson (Engineering)
- **Special thanks** to online creators and FPV drone community for documentation and hardware guidance

---

## 🧾 License

This project is released as **open hardware** and **open-source software**. Reuse, remix, and improve freely with attribution.
