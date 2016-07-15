{
  "targets": [
    {
      "target_name": "nodeTesterAddon",
      "sources": [ "index.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}