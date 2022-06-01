# Disease simulation

## Introduction
This project implements graphic version
of epidemic simulation model on 2D map.

### Society model
Our models create pseudo-random distribution of age to distinguish
different ways of passing-through the infection (probabilities of getting
infected, death, recovery and vaccination differ basen on person's age).

### Person model
As a single person, we can:
- **get infected**
- **infect our neighbours**
- **die because of infection**
- **recover from sickness** - that gives us lower chances of being infected,
lower probability of death and higher chances to recover again
- **get vaccinated** - the same effects as recovery but bigger modifiers
of these constants

### Disease

To model our epidemic, we use parameters such as:
- **contagiousness** - to describe how easily epidemic spreads
- **fatality** - general probability of death when infected
- **cure_difficulty** - how difficult it is to recover
- **vaccine_aversion** - according to recent situation, this
parameter describes probability of people not vaccinating against epidemic

### Other parameters
- **vaccine_invention_speed** - describes probability of fast invention
of vaccine
- **simulation_length** - although our simulation has no strict limit, this parameter
is connected to vaccine_invention_speed, because we have to make a comparison
what "faster" really means

## How to use

**Make sure you have QT library installed on your device.**

1. Run _main.cpp_ file.
2. Two windows should be displayed - "Step" button and a map.
3. Clicking the button will generate next epoque of simulation.
4. Map tiles are coloured in certain manner:

<div style="display:flex">
    <div style="width:100px">
        <div style="background-color:red; width:100px; height:50px"></div>
        <div style="margin: 0 auto; width: fit-content">Dead</div>
    </div>
    <div style="width:100px">
        <div style="background-color:#fffe00; width:100px; height:50px"></div>
        <div style="margin: 0 auto; width: fit-content">Sick</div>
    </div>
    <div style="width:100px">
        <div style="background-color:blue; width:100px; height:50px"></div>
        <div style="margin: 0 auto; width: fit-content">Vaccinated</div>
    </div>
    <div style="width:100px">
        <div style="background-color:#00ff00; width:100px; height:50px"></div>
        <div style="margin: 0 auto; width: fit-content">Convalescent</div>
    </div>
    <div style="width:100px">
        <div style="background-color:green; width:100px; height:50px"></div>
        <div style="margin: 0 auto; width: fit-content">Healthy</div>
    </div>
</div>

#### Unfortunately model parameters cannot be set in gui - in order to change them you have to manually set them in _frontend/Window.cpp_.

