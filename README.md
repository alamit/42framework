# 42framework
Init, unit testing and submission framework for daily projects @ 42.
> You're not stupid, and using a towel while being inside a pool would be stupid. Prefer a diving kit, it'll be of more use.

### Key functionalities:
- Generates a repository from a 42 templated PDF file (reads the sumission files).
- Gitignore everything but the submission files, to prevent repo pollution.
- Provides a test framework and a test library, that allows to test each exercise separately and properly.

## Warning: Alpha version

## Usage

### `init42`

The command `init42` takes three arguments:
- The URL of the PDF file for the day project or the path to the aforementionned PDF file.
- Your repo URL for the day project
- The name of the directory where you want to clone the repo.

For example, if your username is `dtrump` and your repo URL is `vogsphere@vgs.42.us.org:intra/2018/activities/piscine_c_day_04/dtrump` and you would like to write clone your repo in the `d04` folder, then you should use `init42` like this:

```sh
init42 PATH/TO/d04.en.pdf vogsphere@vgs.42.us.org:intra/2018/activities/piscine_c_day_04/dtrump d04
# OR
init42 https://url.to.pdf/d04.en.pdf vogsphere@vgs.42.us.org:intra/2018/activities/piscine_c_day_04/dtrump d04
```

The script will then parse and read the PDF file to generate your repository structure and your submission files. Those files are listed in the **Files to turn in :** section of each exercise.

Then every files other than the submission files those will be added to your `.gitignore` file, which will prevent you from pushing unwanted files to the repo for submission. *You can now use `git add .` safely, it will only add submission files*.

Also, a `tests` folder is created, this folder contains a `.c` file for every exercise, **you must write all you tests in these files.** They are already templated to include the files you need to test for each exercise. Feel free to modify them but you could break the repo.

The test files all includes a library called `test42f`, this library contains test functions to help you writing your tests. The documentation for this library is not yet available but you can read the [header](https://github.com/alamit/42framework/blob/master/lib/test42f/include/test42f.h) and look at the [implementations](https://github.com/alamit/42framework/tree/master/lib/test42f/src) of these functions.

Feel free to ping me on slack (@alamit) if you have any question, I cannot ensure I'll answer quick but I'll do my best.

### `test42`

The command `test42` takes one parameter and one flag:
- The first parameter is the number of the exercise you want to test. For example: `test42 0` or `test42 3` or `test42 10`. Do not add a 0 before numbers < 10.
- The flag `--norm` can be set to check the norm of the submission files after testing. **The flag should be added at the end**. For example: `test42 4 --norm`.

This command will compile all your submission files along with their respective tests and run them. If something goes wrong, you'll notice it.

### `testall42`

This command can only take the `--norm` flag or not, it will run the `test42` command on all you exercises, with the norm flag or not.

## Install instructions

Clone this repository somewhere on your computer.

See the [.zshrc](https://github.com/alamit/42framework/blob/master/.zshrc) file, and reproduce the 2 last functions at the end of the file in your own `~./zshrc` profile.

For example, if you cloned the repo under `~/bin/42framework`, you should add these three functions at the end of your `.zshrc` file:
```sh
init42() {
	sh ~/bin/42framework/init42.sh $@
}

test42() {
	sh ~/bin/42framework/test.sh $@
}

testall42() {
	local idx=0
	local NB_FILES=$(find * -name "ex*" | wc -l | bc | tr -d '\n')
	while [ $idx -lt $NB_FILES ]
	do
		test42 $idx $@
		idx=$(($idx + 1))
	done
}
```

Don't forget to run `source ~/.zshrc` before trying to run commands.

### Credits

Special thanks to Galvin Fielder, for helping me testing the framework during the piscine.
