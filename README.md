# 42framework
Init, unit testing and submission framework for daily projects @42.

## Warning: Beta version

## Install instructions

Clone this repository somewhere on your computer.

See the [.zshrc](https://github.com/alamit/42framework/blob/master/.zshrc) file, and reproduce the 2 last functions at the end of the file in your own `~./zshrc` profile.

For example, if you cloned the repo under `~/bin/42framework`, you should add these three functions at the end of your `.zshrc` file:
```sh
init42() {
	sh ~/scripts/42framework/init42.sh $@
}

test42() {
	sh ~/scripts/42framework/test.sh $@
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
