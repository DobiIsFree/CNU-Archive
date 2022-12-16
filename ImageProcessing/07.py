import numpy as np


def apply_gaussian_filter(src, fsize=3, sigma=1):
    # TODO
    mask = get_Gaussian_mask(fisze, sigma)
    dst = my_filtering(src, mask, 'repetition')
    return dst

def calc_magnitude(Ix, Iy):
    # TODO
    magnitude = np.sqrt((Ix**2) + (Iy**2))
    return magnitude

def calc_angle(Ix, Iy, eps=1e-6):
    # TODO
    angle = np.arctan(Iy/(Ix + eps))
    angle = np.rad2deg(angle)
    return angle

def non_maximum_suppression(magnitude, angle):
    # TODO
    (h, w) = magnitude.shape
    largest_magnitude = np.zeros((h,w))
    for row in range(1, h-1):
        for col in range(1, w-1):
            degree = angle[row, col]

            # gradient의 degree는 edge와 수직방향
            if 0<= degree and degree < 45:
                rate = np.tan(np.deg2rad(degree))
                left_magnitude = (rate) * magnitude[row-1, col-1] + (1-rate) * magnitude[row, col-1]
                right_magnitude = (rate) * magnitude[row+1, col+1] + (1-rate) * magnitude[row, col+1]
                if magnitude[row, col] == max(left_magnitude, magnitude[row, col], right_magnitude):
                    largest_magnitude[row, col] = magnitude[row, col]

# double thresholding
for row in range(h):
    for col in range(w):
        if low_threshold_value <= dst[row, col] < high_threshold_value:
            weak_edge = []
            weak_edge.append((row, col))
            search_weak_edge(dst, weak_edge, high_threshold_value, low_threshold_value)
            if calssify_edge(dst, weak_edge, high_threshold_value):
                for idx in range(len(weak_edge)):
                    (r, c) = weak_edge[idx]
                    dst[r,c] = 255
            else:
                for idx in range(len(weak_edge)):
                    (r,c) = weak_edge[idx]
                    dst[r,c] = 0

dst = dst.astype('float32') / 255.0

