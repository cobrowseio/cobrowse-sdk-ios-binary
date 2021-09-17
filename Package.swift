// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "CobrowseIO",
    platforms: [
        .macOS(.v10_10), .iOS(.v9)
    ],
    products: [
        .library(
            name: "CobrowseIO",
            targets: ["CBIOWrapper"]),
        .library(
            name: "CobrowseIOAppExtension",
            targets: ["CBIOAppExtensionWrapper"]
        )
    ],
    dependencies: [
        .package(
            name: "SwiftCBOR",
            url: "https://github.com/cobrowseio/SwiftCBOR",
            from: "0.4.4"),
        .package(
            name: "Starscream",
            url: "https://github.com/daltoniam/Starscream",
            from: "3.0.0")
    ],
    targets: [
        .target(
            name: "CBIOWrapper",
            dependencies: [
                .target(name: "CobrowseIO"),
                .product(name: "SwiftCBOR", package: "SwiftCBOR"),
                .product(name: "Starscream", package: "Starscream"),
            ],
            path: "wrapper"),
        .target(
            name: "CBIOAppExtensionWrapper",
            dependencies: [
                .target(name: "CobrowseIOAppExtension"),
                .product(name: "SwiftCBOR", package: "SwiftCBOR"),
                .product(name: "Starscream", package: "Starscream"),
            ],
            path: "wrapper-app-extension"),
        .binaryTarget(
            name: "CobrowseIO",
            path: "CobrowseIO.xcframework"),
        .binaryTarget(
            name: "CobrowseIOAppExtension",
            path: "CobrowseIOAppExtension.xcframework"),
    ]
)
