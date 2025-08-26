#!/bin/bash

# Project Deployment Selector
# Choose which project to deploy individually

echo "🚀 Simple Projects - Individual Deployment"
echo "=========================================="
echo ""
echo "Available projects:"
echo "1. QuickQuiz (Static Web App) - Deploy to GitHub Pages"
echo "2. StudyBud (Django App) - Prepare for server deployment"
echo "3. Exit"
echo ""

read -p "Select a project to deploy (1-3): " choice

case $choice in
    1)
        echo ""
        echo "🎯 Deploying QuickQuiz..."
        ./deploy-quickquiz.sh
        echo ""
        echo "🌐 QuickQuiz will be available at:"
        echo "   https://edenmengste.github.io/simple_projects/"
        echo ""
        echo "📝 Don't forget to commit and push:"
        echo "   git add docs/"
        echo "   git commit -m 'Deploy QuickQuiz'"
        echo "   git push"
        ;;
    2)
        echo ""
        echo "🐍 Preparing StudyBud for deployment..."
        ./prepare-studybud.sh
        ;;
    3)
        echo "👋 Goodbye!"
        exit 0
        ;;
    *)
        echo "❌ Invalid selection. Please choose 1, 2, or 3."
        exit 1
        ;;
esac

echo ""
echo "📖 For detailed deployment instructions, see DEPLOYMENT.md"