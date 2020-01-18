import pip._vendor.requests
indeed_result = requests.get("https://indeed.com/jobs?q=python&limit=50")

print(indeed_result)