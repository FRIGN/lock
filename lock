lock() {

	if [[ -f "$1" ]]; then
		echo "$1 is not a lock directory."
		exit 1
	fi

	if mkdir "$1" &>/dev/null;  then
		echo "lock $1 created" >&2
	else
		echo "lock $1 found, waiting for unlock" >&2
		while true; do
			sleep 2;
			if [[ ! -d "$1" ]]; then
				return
			fi
		done
	fi;

}

if [[ "$#" -eq "1" ]]; then
	lock "$1"
else
	echo "please supply one argument: the lock directory."
	exit 1
fi

