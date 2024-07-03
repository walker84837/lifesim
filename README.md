# lifesim: a C implementation of Conway's Game of Life

*Development of this project is somewhat active and maintained. Feel free to open an issue for any questions or suggestions.*

LifeSim implements Conway's Game of Life in C using NCurses for
visualization.

Conway's Game of Life is a classic cellular automaton devised by mathematician
[John Conway](https://simple.wikipedia.org/wiki/John_Horton_Conway). It
simulates the evolution of cells in a grid based on simple rules, creating
complex patterns from initial configurations.

## Table of Contents

  - [Installation](#installation)
  - [Usage](#usage)
  - [Rules of the Game](#rules-of-the-game)
  - [Contributing](#contributing)
  - [License](#license)

## Installation

Ensure you have Raylib installed on your system. Then, compile the project
using a C compiler.

``` console
make -B
```

As of now, configuration is done in [config.def.h](src/config.def.h), where you
can change:
  - grid size (default configuration is 20x20)
  - window resolution (default configuration is 800x800)
  - default speed (default is 1.0x)

## Usage

Run the compiled executable with optional arguments to control simulation speed:

``` console
./lifesim [-s <speed>]
```

- `-s, --speed`: Adjust the simulation speed (default is 1.0x).

### Rules of the Game

The rules governing cell behavior in Conway's Game of Life are:

  - **Survival**: A live cell with 2 or 3 live neighbors survives.
  - **Death**: A live cell with fewer than 2 neighbors dies (loneliness) or with
    more than 3 neighbors dies (overpopulation).
  - **Birth**: A dead cell with exactly 3 neighbors becomes alive
    (reproduction).

For detailed gameplay and additional rules, refer to [Game Of
Life](http://www.bitstorm.org/gameoflife).

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch: `git checkout -b my-new-feature`
3. Make your changes and commit them: `git commit -a`
4. Push to the branch: `git push origin my-new-feature`
5. Create a pull request.

## License

LifeSim is licensed under the [GNU GPLv3](LICENSE.md).
