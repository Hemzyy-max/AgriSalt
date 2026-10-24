# AgriSalt — Smart Soil. Better Crops.

AgriSalt is a proposed low-cost, offline soil screening device for small and marginal farmers. It aims to indicate soil electrical conductivity (EC) and moisture using probes and simple LEDs, without a smartphone or internet connection.

## Status
This is a starter repository. The firmware is a starting example, the circuit PDF is a conceptual wiring reference, BOM prices are estimates, and the CSV has headers only. No hardware has been purchased yet; actual expenditure is ₹0. Do not claim the device is built, calibrated, or validated until that is true.

## System flow
Soil → EC + moisture probes → Arduino Nano → calibration / logic → LED indicators (optional buzzer) → farmer reviews conditions and decides next steps.

## Files
- `circuit/circuit_diagram.pdf`: conceptual pin-level wiring reference.
- `firmware/agrisalt.ino`: starter sketch; thresholds are placeholders.
- `cad/README.md`: enclosure files to add after designing.
- `bom/bill_of_materials.xlsx`: preliminary parts and estimated cost ranges.
- `testing/sensor_readings.csv`: blank data template; no fabricated readings.
- `photos/README.md`: guidance for genuine progress photos.

## Proposed pin mapping
- Moisture analog output → A0
- EC module analog output → A1
- Green LED → D3 through 220–330 Ω resistor
- Yellow LED → D4 through 220–330 Ω resistor
- Red LED → D5 through 220–330 Ω resistor
- Common ground where required by the modules; use a regulated compatible supply.

**Critical:** Confirm the exact EC module's supply voltage, output range, probe type, and signal conditioning from its datasheet. Never connect an unknown output to an Arduino input without verifying compatibility.

## Build and validate
1. Select exact sensor models and check datasheets.
2. Assemble with power disconnected and verify wiring.
3. Upload the sketch and inspect Serial Monitor.
4. Record actual readings using a consistent sampling method and reference measurements.
5. Calibrate the complete setup and validate LED thresholds before field use.
6. Add real dated photos, actual test data, and measured expenditure.

EC readings depend on sensor calibration and measurement conditions. LED thresholds must be validated; AgriSalt is an initial screening aid, not a replacement for laboratory testing or qualified agronomy advice.
