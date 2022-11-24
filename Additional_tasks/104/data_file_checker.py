import yaml


with open("data.yaml", "rt", encoding="utf-8") as f:
    print(yaml.safe_load(f))
