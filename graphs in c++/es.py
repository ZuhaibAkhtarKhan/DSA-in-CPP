import numpy as np
import matplotlib.pyplot as plt
from PIL import Image, ImageOps

# =========================================================
# 1. THICKER TEMPLATES (Better for marker/brush strokes)
# =========================================================
TEMPLATES = {
    0: np.array([
        [0,1,1,1,1,1,0,0], [1,1,0,0,0,1,1,0], [1,1,0,0,0,0,1,1], [1,1,0,0,0,0,1,1],
        [1,1,0,0,0,0,1,1], [1,1,0,0,0,0,1,1], [0,1,1,0,0,1,1,0], [0,0,1,1,1,1,0,0]]),
    1: np.array([
        [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0],
        [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0], [0,0,1,1,1,0,0,0]]),
    2: np.array([
        [0,1,1,1,1,1,0,0], [1,1,0,0,0,1,1,0], [0,0,0,0,0,1,1,0], [0,0,0,0,1,1,0,0],
        [0,0,1,1,1,0,0,0], [0,1,1,0,0,0,0,0], [1,1,0,0,0,0,0,0], [1,1,1,1,1,1,1,1]]),
    3: np.array([
        [0,1,1,1,1,1,1,0], [0,0,0,0,0,1,1,1], [0,0,0,0,0,1,1,0], [0,0,1,1,1,1,0,0],
        [0,0,0,0,0,1,1,0], [0,0,0,0,0,1,1,1], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,0,0]]),
    4: np.array([
        [0,0,0,0,1,1,0,0], [0,0,0,1,1,1,0,0], [0,0,1,1,1,1,0,0], [0,1,1,0,1,1,0,0],
        [1,1,1,1,1,1,1,1], [0,0,0,0,1,1,0,0], [0,0,0,0,1,1,0,0], [0,0,0,0,1,1,0,0]]),
    5: np.array([
        [1,1,1,1,1,1,1,0], [1,1,0,0,0,0,0,0], [1,1,1,1,1,1,0,0], [0,0,0,0,0,1,1,0],
        [0,0,0,0,0,1,1,0], [0,0,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,0,0]]),
    6: np.array([
        [0,0,1,1,1,0,0,0], [0,1,1,0,0,0,0,0], [1,1,0,0,0,0,0,0], [1,1,1,1,1,1,0,0],
        [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,0,0]]),
    7: np.array([
        [1,1,1,1,1,1,1,1], [0,0,0,0,0,1,1,0], [0,0,0,0,1,1,0,0], [0,0,0,1,1,0,0,0],
        [0,0,0,1,1,0,0,0], [0,0,1,1,0,0,0,0], [0,0,1,1,0,0,0,0], [0,0,1,1,0,0,0,0]]),
    8: np.array([
        [0,1,1,1,1,1,0,0], [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,0,0],
        [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,0,0]]),
    9: np.array([
        [0,1,1,1,1,1,0,0], [1,1,0,0,0,1,1,0], [1,1,0,0,0,1,1,0], [0,1,1,1,1,1,1,0],
        [0,0,0,0,0,1,1,0], [0,0,0,0,0,1,1,0], [0,0,0,0,1,1,0,0], [0,0,1,1,1,0,0,0]])
}

def generate_augmented_data(template, n_samples=50):
    matrix_columns = []
    # Make a larger version for shifting
    temp_img = Image.fromarray((template * 255).astype(np.uint8)).resize((16,16), resample=0)
    
    for _ in range(n_samples):
        # Shift
        dx = np.random.randint(-2, 3)
        dy = np.random.randint(-2, 3)
        shifted = ImageOps.expand(temp_img, border=5, fill=0).crop((5+dx, 5+dy, 21+dx, 21+dy))
        shifted = shifted.resize((8,8), Image.Resampling.LANCZOS)
        
        # Noise
        arr = np.array(shifted) / 255.0
        noise = np.random.randn(8, 8) * 0.15 # Reduced noise
        noisy_sample = arr + noise
        matrix_columns.append(noisy_sample.flatten())
    return np.column_stack(matrix_columns)

# =========================================================
# 2. ASPECT RATIO PRESERVING PREPROCESSOR
# =========================================================

def process_user_image(filepath):
    try:
        img = Image.open(filepath).convert('L')
        img = ImageOps.invert(img) # Invert colors
        img = img.point(lambda p: 255 if p > 100 else 0) # Strong threshold
        
        # 1. CROP
        bbox = img.getbbox()
        if bbox:
            img = img.crop(bbox)
        
        # 2. PAD TO SQUARE (Crucial Fix)
        # This prevents the '3' from being squashed into a '1' shape
        w, h = img.size
        max_dim = max(w, h)
        
        # Create a new black square image
        new_img = Image.new('L', (max_dim, max_dim), 0)
        
        # Paste the digit in the center
        offset_x = (max_dim - w) // 2
        offset_y = (max_dim - h) // 2
        new_img.paste(img, (offset_x, offset_y))
        
        # 3. RESIZE
        img = new_img.resize((8, 8), Image.Resampling.LANCZOS)
        
        # 4. NORMALIZE
        img_array = np.array(img) / 255.0
        return img_array
        
    except Exception as e:
        print(f"Error: {e}")
        return None

# =========================================================
# 3. TRAINING
# =========================================================

subspaces = []
print("Training models...")

for digit in range(10):
    A = generate_augmented_data(TEMPLATES[digit])
    U, S, VT = np.linalg.svd(A, full_matrices=False)
    # Rank 6 (Slightly higher rank to capture thickness variations)
    subspaces.append(U[:, :6]) 

print("Ready.")

# =========================================================
# 4. TESTING WITH RECONSTRUCTION VIEW
# =========================================================

while True:
    print("\n" + "-"*40)
    filename = input(">>> Enter filename (e.g. '3.jpg'): ")
    if filename == 'q': break
    
    z_matrix = process_user_image(filename)
    if z_matrix is None: continue
    z = z_matrix.flatten()
    
    residuals = []
    
    # We will store the "Ghost" image of what the computer thinks it sees
    best_projection = None 
    
    for digit in range(10):
        U_k = subspaces[digit]
        projection = U_k @ (U_k.T @ z)
        diff = np.linalg.norm(z - projection)
        residuals.append(diff)
        
        if digit == np.argmin(residuals):
            best_projection = projection.reshape(8,8)

    prediction = np.argmin(residuals)
    
    # VISUALIZATION
    print(f"PREDICTION: {prediction}")
    
    plt.close('all')
    fig, ax = plt.subplots(1, 3, figsize=(12, 4))
    
    # 1. Input
    ax[0].imshow(z_matrix, cmap='gray')
    ax[0].set_title("Input (Squared & 8x8)")
    
    # 2. The Math "Reconstruction"
    # This shows what the model "matched" against
    ax[1].imshow(best_projection, cmap='gray')
    ax[1].set_title(f"Best Math Match (Digit {prediction})")
    
    # 3. Scores
    colors = ['gray'] * 10
    colors[prediction] = 'lime'
    ax[2].bar(range(10), residuals, color=colors)
    ax[2].set_title("Residual Error")
    
    plt.show(block=False)
    plt.pause(0.1)