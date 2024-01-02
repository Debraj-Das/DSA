if [ $# -eq 0 ]; then
  echo "Error: Please provide New directory name"
  exit 1
fi

cp -r "./CPSetup/contest/" "$1"

