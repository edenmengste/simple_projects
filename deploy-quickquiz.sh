#!/bin/bash

# Deployment Script: Deploy QuickQuiz to GitHub Pages
# This script copies the QuickQuiz project to the docs folder for GitHub Pages deployment

echo "🚀 Deploying QuickQuiz to GitHub Pages..."

# Create docs directory if it doesn't exist
if [ ! -d "docs" ]; then
    echo "📁 Creating docs directory..."
    mkdir docs
fi

# Copy QuickQuiz files to docs
echo "📄 Copying QuickQuiz files to docs..."
cp QuickQuiz/* docs/

# Verify files were copied
echo "✅ Files copied to docs:"
ls -la docs/

echo "🎯 QuickQuiz deployment ready!"
echo "💡 Commit and push the docs/ folder to deploy to GitHub Pages"
echo ""
echo "Next steps:"
echo "  git add docs/"
echo "  git commit -m 'Deploy QuickQuiz to GitHub Pages'"
echo "  git push"