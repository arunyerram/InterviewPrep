from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# --- Configuration & Setup ---
chrome_opts = Options()
chrome_opts.add_argument("--headless")
chrome_opts.add_argument("--disable-gpu")

driver = webdriver.Chrome(options=chrome_opts)
wait = WebDriverWait(driver, 10)

BASE_URL = "https://preview--utility-bill-blunders-project.lovable.app"

# List of (account, zip) pairs to test
test_credentials = [
    ("87654321", "90210"),
    ("11223344", "85001"),
    ("99887766", "10001")
]

def test_pay_button(account, zip_code):
    try:
        driver.get(BASE_URL)  # landing page == login

        # 1) Fill in login form
        driver.find_element(By.NAME, "account").send_keys(account)
        driver.find_element(By.NAME, "zip").send_keys(zip_code)
        driver.find_element(By.CSS_SELECTOR, "button[type='submit']").click()

        # 2) Wait for overview
        wait.until(EC.url_contains("/overview"))

        # 3) Find and click Pay Bill
        pay_btn = wait.until(EC.element_to_be_clickable((By.XPATH, "//button[contains(., 'Pay Bill')]")))
        assert pay_btn.is_enabled(), f"[{account}] Pay Bill button should be enabled"
        pay_btn.click()

        # 4) Confirm payment form appears
        wait.until(EC.presence_of_element_located((By.NAME, "cardNumber")))
        wait.until(EC.presence_of_element_located((By.NAME, "expiry")))
        wait.until(EC.presence_of_element_located((By.NAME, "cvv")))

        print(f"✅ [{account}] Pay Bill flow reached payment form successfully.")
    except Exception as e:
        # Capture screenshot & logs on failure
        driver.save_screenshot(f"failure_{account}.png")
        print(f"❌ [{account}] Test failed:", str(e))

# Run the test for each credential
for acct, zp in test_credentials:
    test_pay_button(acct, zp)

driver.quit()
