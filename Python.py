import numpy as np
import matplotlib.pyplot as plt

fs = 8000
dur = 0.5
f = 440.0

N = int(fs * dur)  
n = np.arange(N)  
x = np.sin(2 * np.pi * f * n / fs)

plt.figure(figsize=(10, 4)) 
plt.plot(n[:100], x[:100])