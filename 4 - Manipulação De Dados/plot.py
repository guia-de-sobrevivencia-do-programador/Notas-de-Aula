import matplotlib.pyplot as plt
import seaborn as sns
import sys
import pandas as pd

if __name__ == "__main__":
	data = pd.read_csv("./{}".format(sys.argv[1]), delimiter="\s", header=None, names=["freq", "ip"])
	sns.distplot(data.freq)
	plt.show()

