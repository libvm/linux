#!/bin/bash

target_script=~/rename_files.sh
cat << EOF > "$target_script"
#!/bin/bash

directory_path=~/rename
cd "\$directory_path" || exit 1
file_list=\$(ls)

for file in \$file_list; do
    new_name=\$(echo "\$file" | tr '[:lower:]' '[:upper:]')
    mv "\$file" "\$new_name"
done
EOF

chmod +x "$target_script"
